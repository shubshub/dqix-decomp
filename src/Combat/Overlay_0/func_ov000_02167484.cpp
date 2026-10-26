#include <globaldefs.h>

extern short data_ov000_02183018[4];

// USA: func_ov000_02167484
extern "C" ARM int func_ov000_02167484(short* arr, int count) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < count; j++) {
            if (data_ov000_02183018[i] == arr[j]) break;
        }
        if (j == count) {
            arr[count++] = data_ov000_02183018[i];
        }
    }
    return count;
}
