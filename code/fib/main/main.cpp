//
//  Wasm3 - high performance WebAssembly interpreter written in C.
//
//  Copyright © 2019 Steven Massey, Volodymyr Shymanskyy.
//  All rights reserved.
//

#include "esp_system.h"

#include <stdio.h>
#include <unistd.h>
#include <esp_timer.h>
#include <string>

#include "wasm3.h"
#include "m3_env.h"

#include "extra/fib32.wasm.h"

#define FATAL(msg, ...) { printf("Fatal: " msg "\n", ##__VA_ARGS__); return; }

static void run_wasm(uint32_t input) {
    M3Result result = m3Err_none;

    uint8_t *wasm = (uint8_t *) fib32_wasm;
//    uint8_t *wasm = (uint8_t *) fib32_tail_wasm;
    uint32_t fsize = fib32_wasm_len - 1;
//    uint32_t fsize = fib32_tail_wasm_len - 1;

//    printf("Loading WebAssembly...\n");
    IM3Environment env = m3_NewEnvironment();
    if (!env) FATAL("m3_NewEnvironment failed");

    IM3Runtime runtime = m3_NewRuntime(env, 2*1024, NULL);
    if (!runtime) FATAL("m3_NewRuntime failed");

    IM3Module module;
    result = m3_ParseModule(env, &module, wasm, fsize);
    if (result) FATAL("m3_ParseModule: %s", result);

    result = m3_LoadModule(runtime, module);
    if (result) FATAL("m3_LoadModule: %s", result);

    IM3Function f;
    result = m3_FindFunction(&f, runtime, "fib");
    if (result) FATAL("m3_FindFunction: %s", result);

//    printf("Running...\n");

    const char *i_argv[2] = {std::to_string(input).c_str(), NULL};
    result = m3_CallWithArgs(f, 1, i_argv);

    if (result) FATAL("m3_CallWithArgs: %s", result);

    long value = *(uint64_t *) (runtime->stack);
//    printf("Result: %ld\n", value);
}

uint32_t fib(uint32_t n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

extern "C" void app_main(void) {
    printf("\nWasm3 v" M3_VERSION " on ESP32, build " __DATE__ " " __TIME__ "\n");
    printf("|Input|WASM|NATIVE|\n|---|---|---|\n");
    for (int i = 1; i < 1001; i++) {
        int64_t start_wasm = esp_timer_get_time();
        run_wasm(i);
        int64_t end_wasm = esp_timer_get_time();

        int64_t duration_wasm = (end_wasm - start_wasm) / 1000;

        int64_t start_native = esp_timer_get_time();
        fib(i);
        int64_t end_native = esp_timer_get_time();

        int64_t duration_native = (end_native - start_native) / 1000;

        printf("|%d|%lld|%lld|\n", i, duration_wasm, duration_native);
    }
    sleep(10);
    printf("Restarting...\n\n\n");
    esp_restart();
}
