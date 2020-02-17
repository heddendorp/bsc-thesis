//
// Created by lukas on 16.02.20.
// emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o wasm/test.cpp.wasm wasm/test.cpp && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
// wasmc++ -Os -Wl,--strip-all -Wl,--allow-undefined-file=wasm/test_api.syms -nostdlib wasm/test.cpp -o wasm/test.cpp.wasm && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
//

#define WASM_EXPORT                   extern "C" __attribute__((used)) __attribute__((visibility ("default")))

#include "stdint.h"

WASM_EXPORT
uint32_t run(uint32_t n) {
    uint32_t a[n][n], b[n][n], mul[n][n];

    for (uint32_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        for (uint32_t j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {
            a[i][j]=i+1;
            b[i][j]=i+2;
        }
    }

    for (uint32_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        for (uint32_t j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {
            mul[i][j] = 0;
            for (uint32_t k = 0; k < sizeof(a[0]) / sizeof(a[0][0]); ++k) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return mul[n-1][n-1];
}