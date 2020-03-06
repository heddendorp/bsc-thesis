extern "C" void app_main(void) {
    // Variable initialization

    setup_wasm();

    for (long long &wasm_time : wasm_times) {
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            run_wasm("20");
        }
        int64_t end_time = esp_timer_get_time();
        wasm_time = (end_time - start_time) / 10;
    }

    for (long long &native_time : native_times) {
        int64_t start_time = esp_timer_get_time();
        for (int j = 0; j < 10; ++j) {
            long value = run(20);
        }
        int64_t end_time = esp_timer_get_time();
        native_time = (end_time - start_time) / 10;
    }

    printf("|Run|WASM|NATIVE|\n|---|---|---|\n");
    for (int i = 0; i < sizeof(wasm_times) / sizeof(wasm_times[0]); ++i) {
        printf("|%d|%lld|%lld|\n", i + 1, wasm_times[i], native_times[i]);
    }
    sleep(100);
    printf("Restarting...\n\n\n");
    esp_restart();
}