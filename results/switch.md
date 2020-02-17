# Switch statement

Testing project can be found in the `code` folder.

## Code in test function
```cpp
WASM_EXPORT
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
```
Runs a number of switch calls.

## Results
Following are the average runtimes of on call in microseconds

`Wasm3 v0.4.6 on ESP32, build Feb 17 2020 16:01:18`   
`Setup time: 1299`
|Run    |WASM   |NATIVE |
|---    |---    |---    |
|1      |1028   |0      |
|2      |1021   |0      |
|3      |1021   |0      |
|4      |1021   |0      |
|5      |1021   |0      |
|6      |1021   |0      |
|7      |1021   |0      |
|8      |1021   |0      |
|9      |1021   |0      |
|10     |1021   |0      |
|11     |1021   |0      |
|12     |1021   |0      |
|13     |1021   |0      |
|14     |1021   |0      |
|15     |1021   |0      |
|16     |1021   |0      |
|17     |1022   |0      |
|18     |1021   |0      |
|19     |1021   |0      |
|20     |1021   |0      |
|21     |1021   |0      |
|22     |1021   |0      |
|23     |1021   |0      |
|24     |1021   |0      |
|25     |1021   |0      |
|26     |1021   |0      |
|27     |1021   |0      |
|28     |1021   |0      |
|29     |1021   |0      |
|30     |1021   |0      |
|31     |1021   |0      |
|32     |1021   |0      |
|33     |1021   |0      |
|34     |1021   |0      |
|35     |1021   |0      |
|36     |1021   |0      |
|37     |1021   |0      |
|38     |1021   |0      |
|39     |1021   |0      |
|40     |1021   |0      |
|41     |1021   |0      |
|42     |1021   |0      |
|43     |1021   |0      |
|44     |1021   |0      |
|45     |1021   |0      |
|46     |1021   |0      |
|47     |1021   |0      |
|48     |1021   |0      |
|49     |1021   |0      |
|50     |1021   |0      |
|51     |1021   |0      |
|52     |1021   |0      |
|53     |1021   |0      |
|54     |1021   |0      |
|55     |1021   |0      |
|56     |1021   |0      |
|57     |1021   |0      |
|58     |1021   |0      |
|59     |1021   |0      |
|60     |1021   |0      |
|61     |1021   |0      |
|62     |1021   |0      |
|63     |1022   |0      |
|64     |1021   |0      |
|65     |1021   |0      |
|66     |1021   |0      |
|67     |1021   |0      |
|68     |1021   |0      |
|69     |1021   |0      |
|70     |1021   |0      |
|71     |1021   |0      |
|72     |1021   |0      |
|73     |1021   |0      |
|74     |1021   |0      |
|75     |1021   |0      |
|76     |1021   |0      |
|77     |1021   |0      |
|78     |1021   |0      |
|79     |1021   |0      |
|80     |1021   |0      |
|81     |1021   |0      |
|82     |1021   |0      |
|83     |1021   |0      |
|84     |1021   |0      |
|85     |1021   |0      |
|86     |1021   |0      |
|87     |1021   |0      |
|88     |1021   |0      |
|89     |1021   |0      |
|90     |1021   |0      |
|91     |1021   |0      |
|92     |1021   |0      |
|93     |1021   |0      |
|94     |1021   |0      |
|95     |1021   |0      |
|96     |1021   |0      |
|97     |1021   |0      |
|98     |1021   |0      |
|99     |1021   |0      |
|100    |1021   |0      |
