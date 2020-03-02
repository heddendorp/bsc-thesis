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

m3ApiRawFunction(m3_thesis_sendValue) {
        m3ApiReturnType(uint32_t)
        m3ApiReturn(esp_timer_get_time());
}

M3Result LinkThesis(IM3Runtime runtime) {
    IM3Module module = runtime->modules;
    const char *thesis = "thesis";

    m3_LinkRawFunction(module, thesis, "mark", "i()", &m3_thesis_mark);
    m3_LinkRawFunction(module, thesis, "sendValue", "i()", &m3_thesis_sendValue);
    return m3Err_none;
}

void mark() {
    native_timestamp = esp_timer_get_time();
}

uint32_t sendValue() {
    return esp_timer_get_time();
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
|1      |85     |12     |
|2      |33     |8      |
|3      |33     |8      |
|4      |33     |8      |
|5      |32     |7      |
|6      |33     |8      |
|7      |32     |7      |
|8      |33     |8      |
|9      |32     |8      |
|10     |33     |7      |
|11     |32     |8      |
|12     |33     |7      |
|13     |33     |8      |
|14     |33     |8      |
|15     |33     |7      |
|16     |33     |8      |
|17     |33     |7      |
|18     |32     |8      |
|19     |33     |8      |
|20     |32     |8      |
|21     |33     |8      |
|22     |32     |7      |
|23     |33     |8      |
|24     |32     |7      |
|25     |33     |8      |
|26     |33     |8      |
|27     |33     |7      |
|28     |33     |8      |
|29     |33     |7      |
|30     |33     |8      |
|31     |32     |8      |
|32     |33     |7      |
|33     |32     |8      |
|34     |33     |7      |
|35     |32     |8      |
|36     |33     |8      |
|37     |32     |8      |
|38     |33     |8      |
|39     |32     |7      |
|40     |33     |8      |
|41     |33     |8      |
|42     |33     |8      |
|43     |33     |8      |
|44     |33     |7      |
|45     |33     |8      |
|46     |32     |7      |
|47     |33     |8      |
|48     |32     |8      |
|49     |33     |7      |
|50     |32     |8      |
|51     |33     |7      |
|52     |32     |8      |
|53     |33     |8      |
|54     |33     |8      |
|55     |33     |8      |
|56     |33     |7      |
|57     |33     |8      |
|58     |33     |8      |
|59     |32     |8      |
|60     |33     |8      |
|61     |32     |7      |
|62     |33     |8      |
|63     |32     |7      |
|64     |33     |8      |
|65     |32     |8      |
|66     |33     |7      |
|67     |33     |8      |
|68     |33     |7      |
|69     |33     |8      |
|70     |33     |8      |
|71     |33     |8      |
|72     |32     |8      |
|73     |33     |7      |
|74     |32     |8      |
|75     |33     |7      |
|76     |32     |8      |
|77     |33     |8      |
|78     |32     |7      |
|79     |33     |8      |
|80     |33     |7      |
|81     |33     |8      |
|82     |33     |8      |
|83     |33     |7      |
|84     |33     |8      |
|85     |32     |7      |
|86     |33     |8      |
|87     |32     |8      |
|88     |33     |8      |
|89     |32     |8      |
|90     |33     |7      |
|91     |32     |8      |
|92     |33     |7      |
|93     |33     |8      |
|94     |33     |8      |
|95     |33     |7      |
|96     |33     |8      |
|97     |33     |7      |
|98     |32     |8      |
|99     |33     |8      |
|100    |32     |7      |

## With return value
### Test code
```c++
uint32_t run(uint32_t n) {
    uint32_t result = 0;
    result = sendValue();
    return result;
}
```
### Timings
Times for ten runs each 

`Wasm3 v0.4.6 on ESP32, build Mar  2 2020 14:40:20`   
`Setup time: 1352`
|Run    |Access time    |NATIVE |
|---    |---    |---    |
|1      |81     |12     |
|2      |34     |8      |
|3      |33     |7      |
|4      |34     |8      |
|5      |33     |8      |
|6      |34     |7      |
|7      |33     |8      |
|8      |34     |7      |
|9      |34     |8      |
|10     |34     |8      |
|11     |34     |7      |
|12     |34     |8      |
|13     |34     |7      |
|14     |33     |8      |
|15     |34     |8      |
|16     |33     |29     |
|17     |34     |7      |
|18     |33     |8      |
|19     |34     |8      |
|20     |33     |7      |
|21     |34     |8      |
|22     |34     |7      |
|23     |34     |8      |
|24     |34     |8      |
|25     |34     |7      |
|26     |34     |8      |
|27     |33     |7      |
|28     |34     |8      |
|29     |33     |8      |
|30     |34     |7      |
|31     |33     |8      |
|32     |34     |8      |
|33     |33     |8      |
|34     |34     |8      |
|35     |34     |7      |
|36     |34     |8      |
|37     |34     |8      |
|38     |34     |7      |
|39     |34     |8      |
|40     |33     |7      |
|41     |34     |8      |
|42     |33     |8      |
|43     |34     |7      |
|44     |33     |8      |
|45     |34     |7      |
|46     |33     |8      |
|47     |34     |8      |
|48     |34     |7      |
|49     |34     |8      |
|50     |34     |8      |
|51     |34     |8      |
|52     |34     |8      |
|53     |33     |7      |
|54     |34     |8      |
|55     |33     |8      |
|56     |34     |7      |
|57     |33     |8      |
|58     |34     |7      |
|59     |33     |8      |
|60     |34     |8      |
|61     |34     |7      |
|62     |34     |8      |
|63     |34     |8      |
|64     |34     |8      |
|65     |34     |8      |
|66     |33     |7      |
|67     |34     |8      |
|68     |33     |8      |
|69     |34     |7      |
|70     |33     |8      |
|71     |34     |7      |
|72     |33     |8      |
|73     |34     |8      |
|74     |34     |7      |
|75     |34     |8      |
|76     |34     |7      |
|77     |34     |8      |
|78     |34     |8      |
|79     |33     |7      |
|80     |34     |8      |
|81     |33     |8      |
|82     |34     |8      |
|83     |33     |8      |
|84     |34     |7      |
|85     |33     |8      |
|86     |34     |8      |
|87     |33     |7      |
|88     |34     |8      |
|89     |34     |7      |
|90     |34     |8      |
|91     |34     |8      |
|92     |34     |7      |
|93     |34     |8      |
|94     |33     |7      |
|95     |34     |8      |
|96     |33     |8      |
|97     |34     |7      |
|98     |33     |8      |
|99     |34     |8      |
|100    |33     |7      |
