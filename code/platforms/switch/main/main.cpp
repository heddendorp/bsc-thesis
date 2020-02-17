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
#include <string.h>

#include "wasm3.h"
#include "m3_env.h"

#include "test.wasm.h"
#include "../wasm/test.cpp"

#define FATAL(msg, ...) { printf("Fatal: " msg "\n", ##__VA_ARGS__); return; }


//int64_t native_timestamp;
//
//m3ApiRawFunction(m3_thesis_mark) {
//    native_timestamp = esp_timer_get_time();
//    m3ApiSuccess();
//}
//
//M3Result LinkThesis(IM3Runtime runtime) {
//    IM3Module module = runtime->modules;
//    const char *thesis = "thesis";
//
//    m3_LinkRawFunction(module, thesis, "mark", "i()", &m3_thesis_mark);
//    return m3Err_none;
//}

IM3Environment env;
IM3Runtime runtime;
IM3Module module;
IM3Function f;

static void setup_wasm() {
    M3Result result = m3Err_none;

    auto *wasm = (uint8_t *) wasm_test_cpp_wasm;
    uint32_t fsize = wasm_test_cpp_wasm_len - 1;

    env = m3_NewEnvironment();
    if (!env) FATAL("m3_NewEnvironment failed");

    runtime = m3_NewRuntime(env, 2048, NULL);
    if (!runtime) FATAL("m3_NewRuntime failed");

    result = m3_ParseModule(env, &module, wasm, fsize);
    if (result) FATAL("m3_ParseModule: %s", result);

    result = m3_LoadModule(runtime, module);
    if (result) FATAL("m3_LoadModule: %s", result);

//    result = LinkThesis(runtime);
//    if (result) FATAL("LinkThesis: %s", result);

    result = m3_FindFunction(&f, runtime, "run");
    if (result) FATAL("m3_FindFunction: %s", result);
}

static void run_wasm(const char *input1) {
    M3Result result = m3Err_none;

    const char *i_argv[3] = {input1, NULL};
    result = m3_CallWithArgs(f, 1, i_argv);

    if (result) FATAL("m3_CallWithArgs: %s", result);

    long value = *(uint64_t *) (runtime->stack);
//    printf("Result: %ld\n", value);
}

extern "C" void app_main(void) {
    int64_t start_setup = esp_timer_get_time();
    setup_wasm();
    int64_t end_setup = esp_timer_get_time();
    int64_t wasm_times[100];
    int64_t native_times[100];

    for (long long &wasm_time : wasm_times) {
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            run_wasm("1024");
        }
        int64_t end_time = esp_timer_get_time();
        wasm_time = (end_time - start_time) / 10;
    }

    for (long long &native_time : native_times) {
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            long value = run(1024);
//            printf("Result: %ld\n", value);
        }
        int64_t end_time = esp_timer_get_time();
        native_time = (end_time - start_time) / 10;
    }

    printf("\nWasm3 v" M3_VERSION " on ESP32, build " __DATE__ " " __TIME__ "\n");
    printf("Setup time: %lld\n", (end_setup - start_setup));
    printf("|Run\t|WASM\t|NATIVE\t|\n|---\t|---\t|---\t|\n");
    for (int i = 0; i < sizeof(wasm_times) / sizeof(wasm_times[0]); ++i) {
        printf("|%d\t|%lld\t|%lld\t|\n", i + 1, wasm_times[i], native_times[i]);
    }
    sleep(100);
    printf("Restarting...\n\n\n");
    esp_restart();
}
