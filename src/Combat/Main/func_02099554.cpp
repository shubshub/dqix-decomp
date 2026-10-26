#include <globaldefs.h>

// USA: func_02099554
extern "C" ARM void func_02099554(unsigned short* arr, unsigned short value) {
    int i;
    int j;
    for (i = 0; i < 0x18; i++) {
        if (arr[i] == 0) {
            arr[i] = value;
            return;
        }
    }
    for (j = 0; j < 0x17; j++) {
        arr[j] = arr[j + 1];
    }
    arr[0x17] = value;
}
