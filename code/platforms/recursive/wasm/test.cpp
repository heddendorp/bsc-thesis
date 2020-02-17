// wasmc++ -Os -Wl,--strip-all -Wl,--allow-undefined-file=wasm/test_api.syms -nostdlib wasm/test.cpp -o wasm/test.cpp.wasm && xxd -i wasm/test.cpp.wasm > main/test.wasm.h

#include <stdint.h>
#define WASM_EXPORT                   extern "C" __attribute__((used)) __attribute__((visibility ("default")))

WASM_EXPORT
uint32_t run(uint32_t n) {
    if (n < 2) {
        return n;
    }
    return run(n - 1) + run(n - 2);
}

