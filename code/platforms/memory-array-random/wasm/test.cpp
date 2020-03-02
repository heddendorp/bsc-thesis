//
// Created by lukas on 16.02.20.
// emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o wasm/test.cpp.wasm wasm/test.cpp && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
// wasmc++ -Os -Wl,--strip-all -nostdlib wasm/test.cpp -o wasm/test.cpp.wasm && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
//

#define WASM_EXPORT                   extern "C" __attribute__((used)) __attribute__((visibility ("default")))

#include "stdint.h"


unsigned short lfsr = 0xACE1u;
unsigned bit;

unsigned randWASM()
{
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    return lfsr =  (lfsr >> 1) | (bit << 15);
}

WASM_EXPORT
uint32_t run(uint32_t n) {
    uint32_t array1[n];

    for (int i = 0; i < n; ++i) {
        int32_t val = randWASM() % n;
        array1[val] = i;
    }
    uint32_t nextStep = 1;
    for (int i = 0; i < n; ++i) {
        int32_t val = randWASM() % n;
        nextStep = array1[val] = i;
    }
    return nextStep;
}