static void run_wasm(const char *input1) {
    M3Result result = m3Err_none;

    const char *i_argv[3] = {input1, NULL};
    result = m3_CallWithArgs(f, 1, i_argv);

    if (result) FATAL("m3_CallWithArgs: %s", result);

    long value = *(uint64_t *) (runtime->stack);
}