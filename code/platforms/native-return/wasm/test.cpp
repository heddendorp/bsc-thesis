//
// Created by lukas on 16.02.20.
// emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o wasm/test.cpp.wasm wasm/test.cpp && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
// wasmc++ -Os -Wl,--strip-all -Wl,--allow-undefined-file=wasm/test_api.syms -nostdlib wasm/test.cpp -o wasm/test.cpp.wasm && xxd -i wasm/test.cpp.wasm > main/test.wasm.h
//

#include "test_api.h"

WASM_EXPORT
uint32_t run(uint32_t n) {
    uint32_t result = 0;
    result = sendValue();
    return result;
}