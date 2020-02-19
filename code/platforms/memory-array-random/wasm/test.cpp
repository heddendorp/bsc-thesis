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

void random_shuffle(unsigned int *list, int32_t N)
{
    for (int32_t i=0; i<N-1; ++i) {
        int32_t swap_ix = i + randWASM() % (N-i);
        unsigned int tmp = list[swap_ix];
        list[swap_ix] = list[i];
        list[i] = tmp;
    }
}

WASM_EXPORT
uint32_t run(uint32_t n) {
    uint32_t array1[n];

    random_shuffle(array1, n);
    for (int i = 0; i < n; ++i) {
        array1[i] = i+1;
    }
    array1[n-1] = 0;
    uint32_t nextStep = 1;
    while(nextStep){
        nextStep = array1[nextStep];
    }
    return nextStep;
}