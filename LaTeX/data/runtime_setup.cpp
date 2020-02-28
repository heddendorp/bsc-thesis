IM3Environment env;
IM3Runtime runtime;
IM3Module module;
IM3Function f;

static void setup_wasm() {
        M3Result result = m3Err_none;
    
        auto *wasm = (uint8_t *) wasm_test_cpp_wasm;
        uint32_t fsize = wasm_test_cpp_wasm_len - 1;
    
        env = m3_NewEnvironment();
        if (!env) FATAL("m3_NewEnvironment failed");
    
        runtime = m3_NewRuntime(env, 2048, NULL);
        if (!runtime) FATAL("m3_NewRuntime failed");
    
        result = m3_ParseModule(env, &module, wasm, fsize);
        if (result) FATAL("m3_ParseModule: %s", result);
    
        result = m3_LoadModule(runtime, module);
        if (result) FATAL("m3_LoadModule: %s", result);
    
    //    result = LinkThesis(runtime);
    //    if (result) FATAL("LinkThesis: %s", result);
    
        result = m3_FindFunction(&f, runtime, "run");
        if (result) FATAL("m3_FindFunction: %s", result);
    }
}