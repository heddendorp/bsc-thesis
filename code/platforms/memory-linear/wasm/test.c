/*
 * emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o wasm/test.c.wasm wasm/test.c && xxd -i wasm/test.c.wasm > main/test.wasm.h
 * emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o main/test.cpp.wasm main/test.cpp && xxd -i wasm/test.c.wasm > main/test.wasm.h
 */

#include <stdint.h>
#define WASM_EXPORT __attribute__((used)) __attribute__((visibility ("default")))

WASM_EXPORT
uint32_t run(uint32_t n) {
    double testarray[1000];
    for (int i = 0; i < 1000; ++i) {
        testarray[i] = i*2;
    }
    for (int i = 0; i < 1000; ++i) {
        double item = testarray[i];
        testarray[i] = item*2;
    }
    return n;
}
/*void run(uint32_t n) {
    double testarray[n];
    for (int i = 0; i < n; ++i) {
        testarray[i] = i*2;
    }
    for (int i = 0; i < n; ++i) {
        testarray[i] = testarray[i]*2;
    }
}*/

