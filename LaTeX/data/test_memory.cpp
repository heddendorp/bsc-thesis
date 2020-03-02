uint32_t run(uint32_t n) {
    uint32_t array1[n];
    
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