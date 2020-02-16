# Fibonacci

### C-code
```c++
uint32_t fib(uint32_t n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

### Testing code
```c++
extern "C" void app_main(void) {
    int64_t start_setup = esp_timer_get_time();
    setup_wasm();
    int64_t end_setup = esp_timer_get_time();
    int64_t wasm_times[100];
    int64_t native_times[100];

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
            fib(20);
        }
        int64_t end_time = esp_timer_get_time();
        native_time = (end_time - start_time) / 10;
    }

    printf("\nWasm3 v" M3_VERSION " on ESP32, build " __DATE__ " " __TIME__ "\n");
    printf("Setup time: %lld\n", (end_setup - start_setup));
    printf("|Run|WASM|NATIVE|\n|---|---|---|\n");
    for (int i = 0; i < sizeof(wasm_times) / sizeof(wasm_times[0]); ++i) {
        printf("|%d|%lld|%lld|\n", i + 1, wasm_times[i], native_times[i]);
    }
    sleep(10);
    printf("Restarting...\n\n\n");
    esp_restart();
}
```

## Results
`Wasm3 v0.4.6 on ESP32, build Feb 10 2020 11:22:28`   
`Setup time: 901`
|Run|WASM|NATIVE|
|---|---|---|
|1|41728|1002|
|2|41722|1000|
|3|41721|1000|
|4|41722|1000|
|5|41721|1000|
|6|41721|1000|
|7|41722|1000|
|8|41722|1000|
|9|41721|1000|
|10|41721|1000|
|11|41722|1000|
|12|41721|1000|
|13|41721|1000|
|14|41721|1000|
|15|41721|1000|
|16|41721|1000|
|17|41721|1000|
|18|41721|1000|
|19|41721|1001|
|20|41722|1000|
|21|41721|1000|
|22|41722|1000|
|23|41721|1000|
|24|41721|1000|
|25|41722|1001|
|26|41722|1000|
|27|41721|1000|
|28|41721|1000|
|29|41722|1000|
|30|41722|1000|
|31|41721|1000|
|32|41721|1000|
|33|41722|1000|
|34|41722|1000|
|35|41721|1000|
|36|41722|1000|
|37|41721|1000|
|38|41721|1000|
|39|41721|1000|
|40|41722|1000|
|41|41721|1000|
|42|41721|1000|
|43|41721|1000|
|44|41722|1000|
|45|41722|1001|
|46|41721|1000|
|47|41722|1000|
|48|41721|1000|
|49|41721|1000|
|50|41721|1000|
|51|41721|1000|
|52|41722|1000|
|53|41721|1000|
|54|41722|1000|
|55|41721|1000|
|56|41721|1000|
|57|41721|1000|
|58|41721|1000|
|59|41721|1000|
|60|41721|1000|
|61|41722|1000|
|62|41722|1000|
|63|41722|1000|
|64|41721|1000|
|65|41722|1000|
|66|41721|1000|
|67|41721|1000|
|68|41721|1001|
|69|41721|1000|
|70|41722|1001|
|71|41721|1000|
|72|41721|1000|
|73|41721|1000|
|74|41721|1000|
|75|41721|1000|
|76|41721|1001|
|77|41722|1000|
|78|41721|1001|
|79|41721|1000|
|80|41721|1000|
|81|41722|1000|
|82|41721|1000|
|83|41722|1000|
|84|41721|1000|
|85|41721|1000|
|86|41722|1000|
|87|41721|1000|
|88|41721|1000|
|89|41721|1000|
|90|41722|1000|
|91|41722|1000|
|92|41722|1000|
|93|41721|1000|
|94|41721|1001|
|95|41722|1000|
|96|41721|1000|
|97|41721|1000|
|98|41721|1000|
|99|41721|1000|
|100|41721|1000|


#### Notice
 ⚠️ This architecture/compiler currently fails to perform TCO (Tail Call Optimization/Elimination), which leads to sub-optimal interpreter behaviour (intense native stack usage, lower performance). There are plans to improve this in future 🦄.