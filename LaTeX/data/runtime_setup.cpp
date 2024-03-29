IM3Environment env;
IM3Runtime runtime;
IM3Module module;
IM3Function f;

static void setup_wasm() {
        M3Result result = m3Err_none;
    
        auto *wasm = (uint8_t *) wasm_test_cpp_wasm; (*\label{r-s-cpp:import1}*)
        uint32_t fsize = wasm_test_cpp_wasm_len - 1; (*\label{r-s-cpp:import2}*)
    
        env = m3_NewEnvironment(); // Error output omitted
        runtime = m3_NewRuntime(env, 2048, NULL);
        result = m3_ParseModule(env, &module, wasm, fsize);
        result = m3_LoadModule(runtime, module);
        result = LinkThesis(runtime);(*\label{r-s-cpp:link}*)
        result = m3_FindFunction(&f, runtime, "run"); (*\label{r-s-cpp:function}*)
    }
}