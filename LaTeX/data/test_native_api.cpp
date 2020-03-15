extern "C" {

    WASM_IMPORT("thesis", "sendValue")   uint32_t sendValue    (void);
    WASM_IMPORT("thesis", "mark")        void mark             (void);

}