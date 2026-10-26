#include <globaldefs.h>

// USA: func_ov000_0215a8d4
extern "C" ARM void func_ov000_0215a8d4(unsigned char* obj, int idx) {
    unsigned char* arr = obj + 0x8d5c;
    arr[idx]++;
    if (arr[idx] > 0x63) {
        arr[idx] = 0x63;
    }
    if (idx == 9) {
        arr[idx] = 1;
    }
}
