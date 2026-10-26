#include <globaldefs.h>

extern "C" int func_ov031_0220bb24(unsigned short* arr, int len);

// USA: func_ov031_0220bb4c
extern "C" ARM int func_ov031_0220bb4c(unsigned short* arr, int len) {
    if (arr[len - 1] & 0x8000) {
        return -1;
    }
    return func_ov031_0220bb24(arr, len) != 0;
}
