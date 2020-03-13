uint32_t run(uint32_t n) {
    uint32_t array1[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    uint32_t result = 200;
    for (int i = 0; i < n; ++i) {
        uint32_t compare = i % 20;
        switch (compare) {
            case 0:
                result = array1[0];
                break;
            case 1:
                result = array1[1];
                break;
            // Some cases omitted
            case 18:
                result = array1[18];
                break;
            case 19:
                result = array1[19];
                break;
            default:
                result = 100;
                break;
        }
    }
    return result;
}