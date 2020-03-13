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
Run     & WASM  & NATIVE        //
1       & 84    & 12    //
2       & 32    & 7     //
3       & 33    & 8     //
4       & 32    & 7     //
5       & 33    & 8     //
6       & 33    & 8     //
7       & 33    & 7     //
8       & 33    & 8     //
9       & 33    & 7     //
10      & 33    & 8     //
11      & 32    & 8     //
12      & 33    & 7     //
13      & 32    & 8     //
14      & 33    & 7     //
15      & 32    & 8     //
16      & 33    & 8     //
17      & 32    & 8     //
18      & 33    & 8     //
19      & 32    & 7     //
20      & 33    & 8     //
21      & 33    & 7     //
22      & 33    & 8     //
23      & 33    & 8     //
24      & 33    & 7     //
25      & 33    & 8     //
26      & 32    & 7     //
27      & 33    & 8     //
28      & 32    & 8     //
29      & 33    & 7     //
30      & 32    & 8     //
31      & 33    & 7     //
32      & 32    & 8     //
33      & 33    & 8     //
34      & 33    & 8     //
35      & 33    & 8     //
36      & 33    & 7     //
37      & 33    & 8     //
38      & 33    & 8     //
39      & 32    & 8     //
40      & 33    & 8     //
41      & 32    & 7     //
42      & 33    & 8     //
43      & 32    & 7     //
44      & 33    & 8     //
45      & 32    & 8     //
46      & 33    & 7     //
47      & 33    & 8     //
48      & 33    & 7     //
49      & 33    & 8     //
50      & 33    & 8     //
51      & 33    & 8     //
52      & 32    & 8     //
53      & 33    & 7     //
54      & 32    & 8     //
55      & 33    & 7     //
56      & 32    & 8     //
57      & 33    & 8     //
58      & 32    & 7     //
59      & 33    & 8     //
60      & 33    & 7     //
61      & 33    & 8     //
62      & 33    & 8     //
63      & 33    & 7     //
64      & 33    & 8     //
65      & 32    & 7     //
66      & 33    & 8     //
67      & 32    & 8     //
68      & 33    & 8     //
69      & 32    & 8     //
70      & 33    & 7     //
71      & 32    & 8     //
72      & 33    & 7     //
73      & 33    & 8     //
74      & 33    & 8     //
75      & 33    & 7     //
76      & 33    & 8     //
77      & 33    & 7     //
78      & 32    & 8     //
79      & 33    & 8     //
80      & 32    & 7     //
81      & 33    & 8     //
82      & 32    & 7     //
83      & 33    & 8     //
84      & 32    & 8     //
85      & 33    & 8     //
86      & 33    & 8     //
87      & 33    & 7     //
88      & 33    & 8     //
89      & 33    & 7     //
90      & 33    & 8     //
91      & 32    & 8     //
92      & 33    & 7     //
93      & 32    & 8     //
94      & 33    & 7     //
95      & 32    & 8     //
96      & 33    & 8     //
97      & 32    & 8     //
98      & 33    & 8     //
99      & 32    & 7     //
100     & 33    & 8     //


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
Run     & WASM  & NATIVE        //
1       & 82    & 12    //
2       & 33    & 7     //
3       & 34    & 8     //
4       & 34    & 8     //
5       & 34    & 7     //
6       & 34    & 8     //
7       & 34    & 7     //
8       & 34    & 8     //
9       & 33    & 8     //
10      & 34    & 7     //
11      & 33    & 8     //
12      & 34    & 8     //
13      & 33    & 8     //
14      & 34    & 8     //
15      & 33    & 7     //
16      & 34    & 30    //
17      & 34    & 8     //
18      & 34    & 7     //
19      & 34    & 8     //
20      & 34    & 7     //
21      & 34    & 8     //
22      & 33    & 8     //
23      & 34    & 7     //
24      & 33    & 8     //
25      & 34    & 8     //
26      & 33    & 8     //
27      & 34    & 8     //
28      & 33    & 7     //
29      & 34    & 8     //
30      & 33    & 8     //
31      & 34    & 7     //
32      & 34    & 8     //
33      & 34    & 7     //
34      & 34    & 8     //
35      & 34    & 8     //
36      & 34    & 7     //
37      & 33    & 8     //
38      & 34    & 7     //
39      & 33    & 8     //
40      & 34    & 8     //
41      & 33    & 7     //
42      & 34    & 8     //
43      & 33    & 8     //
44      & 34    & 8     //
45      & 34    & 8     //
46      & 34    & 7     //
47      & 34    & 8     //
48      & 34    & 8     //
49      & 34    & 7     //
50      & 33    & 8     //
51      & 34    & 7     //
52      & 33    & 8     //
53      & 34    & 8     //
54      & 33    & 7     //
55      & 34    & 8     //
56      & 33    & 7     //
57      & 34    & 8     //
58      & 34    & 8     //
59      & 34    & 7     //
60      & 34    & 8     //
61      & 34    & 8     //
62      & 34    & 7     //
63      & 33    & 8     //
64      & 34    & 7     //
65      & 33    & 8     //
66      & 34    & 8     //
67      & 33    & 7     //
68      & 34    & 8     //
69      & 33    & 7     //
70      & 34    & 8     //
71      & 34    & 8     //
72      & 34    & 7     //
73      & 34    & 8     //
74      & 34    & 8     //
75      & 34    & 8     //
76      & 33    & 8     //
77      & 34    & 7     //
78      & 33    & 8     //
79      & 34    & 8     //
80      & 33    & 7     //
81      & 34    & 8     //
82      & 33    & 7     //
83      & 34    & 8     //
84      & 34    & 8     //
85      & 34    & 7     //
86      & 34    & 8     //
87      & 34    & 7     //
88      & 34    & 8     //
89      & 33    & 8     //
90      & 34    & 7     //
91      & 33    & 8     //
92      & 34    & 8     //
93      & 33    & 8     //
94      & 34    & 8     //
95      & 33    & 7     //
96      & 34    & 8     //
97      & 34    & 8     //
98      & 34    & 7     //
99      & 34    & 8     //
100     & 34    & 7     //


