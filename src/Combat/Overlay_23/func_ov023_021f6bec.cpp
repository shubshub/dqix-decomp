#include <globaldefs.h>

// USA: func_ov023_021f6bec
extern "C" ARM void func_ov023_021f6bec(void* obj, int arg1, unsigned int arg2, unsigned int count) {
    if (arg2 >= 0x80) return;
    int* arr = (int*)((char*)obj + 8 + (arg1 << 4));
    unsigned short n = 0;
    while (n < count) {
        int idx = arg2 / 4;
        arr[idx] |= 1 << (arg2 & 3);
        arg2++;
        n++;
    }
}
