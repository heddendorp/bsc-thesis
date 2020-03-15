uint32_t run(uint32_t n) {(*\label{t-m-cpp:input}*)
    uint32_t a[n][n], b[n][n], mul[n][n];

    for (uint32_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) { (*\label{t-m-cpp:init}*)
        for (uint32_t j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {
            a[i][j]=i+1;
            b[i][j]=i+2;
        }
    }

    for (uint32_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {(*\label{t-m-cpp:calc_start}*)
        for (uint32_t j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {
            mul[i][j] = 0;
            for (uint32_t k = 0; k < sizeof(a[0]) / sizeof(a[0][0]); ++k) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }(*\label{t-m-cpp:calc_end}*)

    return mul[n-1][n-1]; (*\label{t-m-cpp:value}*)
}