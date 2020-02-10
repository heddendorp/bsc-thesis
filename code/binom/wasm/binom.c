/*
 * emcc -g0 -O3 -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -s ONLY_MY_CODE=1 -o fib.c.wasm fib.c
 * gcc -g0 -O3 fib.c -o fib.c.elf
 */

#include <stdint.h>
#define WASM_EXPORT __attribute__((used)) __attribute__((visibility ("default")))

WASM_EXPORT
uint32_t binomial(uint32_t  n, uint32_t m)
{
    if (m != 0 && n != m) {
        return binomial(n-1, m) + binomial(n-1, m-1);
    } else {
        return 1;
    }
}

