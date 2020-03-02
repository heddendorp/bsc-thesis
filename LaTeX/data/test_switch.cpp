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
            case 2:
                result = array1[2];
                break;
            case 3:
                result = array1[3];
                break;
            case 4:
                result = array1[4];
                break;
            case 5:
                result = array1[5];
                break;
            case 6:
                result = array1[6];
                break;
            case 7:
                result = array1[7];
                break;
            case 8:
                result = array1[8];
                break;
            case 9:
                result = array1[9];
                break;
            case 10:
                result = array1[10];
                break;
            case 11:
                result = array1[11];
                break;
            case 12:
                result = array1[12];
                break;
            case 13:
                result = array1[13];
                break;
            case 14:
                result = array1[14];
                break;
            case 15:
                result = array1[15];
                break;
            case 16:
                result = array1[16];
                break;
            case 17:
                result = array1[17];
                break;
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