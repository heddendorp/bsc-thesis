//
// Created by lukas on 16.02.20.
//

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
