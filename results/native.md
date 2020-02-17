# Native calls

Testing project can be found in the `code` folder.

## Without return value
### Additons to the main file
```cpp
int64_t native_timestamp;

m3ApiRawFunction(m3_thesis_mark) {
    native_timestamp = esp_timer_get_time();
    m3ApiSuccess();
}

M3Result LinkThesis(IM3Runtime runtime) {
    IM3Module module = runtime->modules;
    const char *thesis = "thesis";

    m3_LinkRawFunction(module, thesis, "mark", "i()", &m3_thesis_mark);
    return m3Err_none;
}

void mark() {
    native_timestamp = esp_timer_get_time();
}
```
This code links the native function called from the wasm module to the runtime and also includes a native version of the linked function to be called fo the benchmark.

### Additional api file
```cpp
#ifndef WASM3_TEST_API_H
#define WASM3_TEST_API_H

#include <stdint.h>

#define WASM_EXPORT                   extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(NAME)          WASM_EXPORT __attribute__((export_name(NAME)))
#define WASM_IMPORT(MODULE, NAME)      __attribute__((import_module(MODULE))) __attribute__((import_name(NAME)))

extern "C" {

WASM_IMPORT("thesis", "sendValue")   uint32_t sendValue    (void);
WASM_IMPORT("thesis", "mark")        void mark             (void);

}

#endif //WASM3_TEST_API_H
```
`test_api.h` allows using the external functions in the wasm module.

### Results
The results this time are the difference in microseconds from the timestamp created by the called function to the timestamp after the test exections have finished.

`Wasm3 v0.4.6 on ESP32, build Feb 17 2020 15:58:02`   
`Setup time: 1332`
|Run    |WASM   |NATIVE |
|---    |---    |---    |
|1      |1      |1      |
|2      |1      |0      |
|3      |1      |1      |
|4      |1      |1      |
|5      |1      |1      |
|6      |1      |0      |
|7      |1      |1      |
|8      |1      |1      |
|9      |2      |1      |
|10     |1      |0      |
|11     |1      |1      |
|12     |1      |1      |
|13     |1      |0      |
|14     |1      |1      |
|15     |1      |1      |
|16     |1      |1      |
|17     |1      |0      |
|18     |1      |1      |
|19     |1      |1      |
|20     |1      |0      |
|21     |1      |0      |
|22     |1      |1      |
|23     |1      |1      |
|24     |1      |0      |
|25     |1      |1      |
|26     |1      |1      |
|27     |1      |1      |
|28     |1      |0      |
|29     |1      |1      |
|30     |1      |1      |
|31     |1      |0      |
|32     |1      |0      |
|33     |1      |1      |
|34     |1      |1      |
|35     |1      |0      |
|36     |1      |1      |
|37     |1      |1      |
|38     |1      |1      |
|39     |1      |0      |
|40     |2      |1      |
|41     |1      |1      |
|42     |1      |0      |
|43     |1      |1      |
|44     |1      |1      |
|45     |1      |1      |
|46     |1      |0      |
|47     |1      |1      |
|48     |1      |1      |
|49     |2      |1      |
|50     |1      |0      |
|51     |1      |1      |
|52     |1      |1      |
|53     |1      |0      |
|54     |1      |1      |
|55     |1      |1      |
|56     |1      |1      |
|57     |1      |0      |
|58     |1      |1      |
|59     |1      |1      |
|60     |1      |0      |
|61     |1      |0      |
|62     |1      |1      |
|63     |1      |1      |
|64     |1      |0      |
|65     |1      |1      |
|66     |1      |1      |
|67     |1      |1      |
|68     |1      |0      |
|69     |1      |1      |
|70     |1      |1      |
|71     |1      |0      |
|72     |1      |0      |
|73     |1      |1      |
|74     |1      |1      |
|75     |1      |0      |
|76     |1      |1      |
|77     |1      |1      |
|78     |1      |1      |
|79     |1      |0      |
|80     |2      |1      |
|81     |1      |1      |
|82     |1      |0      |
|83     |1      |1      |
|84     |1      |1      |
|85     |1      |1      |
|86     |1      |0      |
|87     |1      |1      |
|88     |1      |1      |
|89     |2      |1      |
|90     |1      |0      |
|91     |1      |1      |
|92     |1      |1      |
|93     |1      |0      |
|94     |1      |1      |
|95     |1      |1      |
|96     |1      |1      |
|97     |1      |0      |
|98     |1      |1      |
|99     |1      |1      |
|100    |1      |0      |
