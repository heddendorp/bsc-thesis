//
//  Wasm3 - high performance WebAssembly interpreter written in C.
//
//  Copyright © 2019 Steven Massey, Volodymyr Shymanskyy.
//  All rights reserved.
//

#include "esp_system.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <esp_timer.h>
#include <sstream>
#include <string.h>

#include "wasm3.h"
#include "m3_env.h"

#include "binom.wasm.h"

#define FATAL(msg, ...) { printf("Fatal: " msg "\n", ##__VA_ARGS__); return; }

static void run_wasm(uint32_t input1, uint32_t input2) {
    M3Result result = m3Err_none;

    uint8_t *wasm = (uint8_t *) binom_c_wasm;
    uint32_t fsize = binom_c_wasm_len - 1;

//    printf("Loading WebAssembly...\n");
    IM3Environment env = m3_NewEnvironment();
    if (!env) FATAL("m3_NewEnvironment failed");

    IM3Runtime runtime = m3_NewRuntime(env, 4 * 1024, NULL);
    if (!runtime) FATAL("m3_NewRuntime failed");

    IM3Module module;
    result = m3_ParseModule(env, &module, wasm, fsize);
    if (result) FATAL("m3_ParseModule: %s", result);

    result = m3_LoadModule(runtime, module);
    if (result) FATAL("m3_LoadModule: %s", result);

    IM3Function f;
    result = m3_FindFunction(&f, runtime, "binomial");
    if (result) FATAL("m3_FindFunction: %s", result);

//    printf("Running...\n");
    std::stringstream st1;
    std::stringstream st2;
    st1 << input1;
    st2 << input2;
    std::string temp_str = st1.str();
    std::string temp_str2 = st2.str();
    const char *i_argv[3] = {temp_str.c_str(), temp_str2.c_str(), NULL};
    result = m3_CallWithArgs(f, 2, i_argv);

    if (result) FATAL("m3_CallWithArgs: %s", result);

    long value = *(uint64_t *) (runtime->stack);
//    printf("Result: %ld\n", value);
}

uint32_t binomial(uint32_t n, uint32_t m) {
    if (m != 0 && n != m) {
        return binomial(n - 1, m) + binomial(n - 1, m - 1);
    } else {
        return 1;
    }
}

extern "C" void app_main(void) {
    printf("\nWasm3 v" M3_VERSION " on ESP32, build " __DATE__ " " __TIME__ "\n");
    printf("|Input|WASM|NATIVE|\n|---|---|---|\n");
    for (int i = 20; i < 30; i++) {
        for (int j = 1; j < i; j++) {
            int64_t start_wasm = esp_timer_get_time();
            run_wasm(i, j);
            int64_t end_wasm = esp_timer_get_time();

            int64_t duration_wasm = (end_wasm - start_wasm) / 1000;

            int64_t start_native = esp_timer_get_time();
            long value = binomial(i, j);
            int64_t end_native = esp_timer_get_time();
//            printf("Result: %ld\n", value);
            int64_t duration_native = (end_native - start_native) / 1000;

            printf("|(%d,%d)|%lld|%lld|\n", i, j, duration_wasm, duration_native);
        }
    }
    sleep(10);
    printf("Restarting...\n\n\n");
    esp_restart();
}
