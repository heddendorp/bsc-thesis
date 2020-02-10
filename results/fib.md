# Fibonacci

### C-code
```c++
uint32_t fib(uint32_t n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
```

### WASM-module
```c++
unsigned char fib32_wasm[] = {
  0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x06, 0x01, 0x60,
  0x01, 0x7f, 0x01, 0x7f, 0x03, 0x02, 0x01, 0x00, 0x07, 0x07, 0x01, 0x03,
  0x66, 0x69, 0x62, 0x00, 0x00, 0x0a, 0x1f, 0x01, 0x1d, 0x00, 0x20, 0x00,
  0x41, 0x02, 0x49, 0x04, 0x40, 0x20, 0x00, 0x0f, 0x0b, 0x20, 0x00, 0x41,
  0x02, 0x6b, 0x10, 0x00, 0x20, 0x00, 0x41, 0x01, 0x6b, 0x10, 0x00, 0x6a,
  0x0f, 0x0b
};
unsigned int fib32_wasm_len = 62;
```

### Testing code
```c++
extern "C" void app_main(void) {
    printf("\nWasm3 v" M3_VERSION " on ESP32, build " __DATE__ " " __TIME__ "\n");
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
```

## Results
`Wasm3 v0.4.6 on ESP32, build Feb 10 2020 11:22:28`
|Input|WASM|NATIVE|
|---|---|---|
|20|43|1|
|21|69|1|
|22|112|2|
|23|181|4|
|24|294|6|
|25|475|11|
|26|769|17|
|27|1245|29|
|28|2014|47|
|29|3260|76|
|30|5274|123|

#### Notice
 ⚠️ This architecture/compiler currently fails to perform TCO (Tail Call Optimization/Elimination), which leads to sub-optimal interpreter behaviour (intense native stack usage, lower performance). There are plans to improve this in future 🦄.