/*
 * emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o wasm/test.c.wasm wasm/test.c && xxd -i wasm/test.c.wasm > main/test.wasm.h
 */

#include <stdint.h>
#define WASM_EXPORT __attribute__((used)) __attribute__((visibility ("default")))

WASM_EXPORT
uint32_t testfunction(uint32_t n) {
    if (n < 2) {
        return n;
    }
    return testfunction(n - 1) + testfunction(n - 2);
}

