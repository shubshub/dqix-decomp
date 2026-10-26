#include <globaldefs.h>

// USA: func_ov023_021f6e34
extern "C" ARM void func_ov023_021f6e34(void* obj, int idx, unsigned int bit) {
    if (bit >= 0x10) return;
    unsigned short* arr = (unsigned short*)((char*)obj + 0x2c);
    arr[idx] &= ~(1 << bit);
}
