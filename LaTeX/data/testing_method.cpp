extern "C" void app_main(void) {
    // Variable initialization

    setup_wasm(); // Explained in Listing (*\ref{lst:runtime_setup}\label{t-s-cpp:setup}*)

    for (long long &wasm_time : wasm_times) {(*\label{t-s-cpp:start_wasm}*)
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            run_wasm("20"); // Explained in Listing (*\ref{lst:test_exec}\label{t-s-cpp:run_wasm}*)
        }
        int64_t end_time = esp_timer_get_time();
        wasm_time = (end_time - start_time) / 10;
    }(*\label{t-s-cpp:end_wasm}*)

    for (long long &native_time : native_times) {(*\label{t-s-cpp:start_native}*)
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            long value = run(20);(*\label{t-s-cpp:run_native}*)
        }
        int64_t end_time = esp_timer_get_time();
        native_time = (end_time - start_time) / 10;
    }(*\label{t-s-cpp:end_native}*)

    printf("|Run|WASM|NATIVE|\n|---|---|---|\n");
    for (int i = 0; i < sizeof(wasm_times) / sizeof(wasm_times[0]); ++i) {(*\label{t-s-cpp:print}*)
        printf("|%d|%lld|%lld|\n", i + 1, wasm_times[i], native_times[i]);
    }
    sleep(100);
    printf("Restarting...\n\n\n");
    esp_restart(); (*\label{t-s-cpp:restart}*)
}