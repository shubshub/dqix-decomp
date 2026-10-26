#include <globaldefs.h>

#pragma opt_arithtransformation off

// USA: func_ov023_021f6c3c
extern "C" ARM void func_ov023_021f6c3c(void* base, unsigned int idx1, unsigned int arg2,
                                unsigned int count) {
    if (arg2 >= 0x80) {
        return;
    }
    unsigned short i = 0;
    while (i < count) {
        unsigned int* arr = (unsigned int*)((char*)base + 8 + (idx1 << 4));
        unsigned int word = arr[arg2 >> 2];
        unsigned int mask = ~(1u << (arg2 & 3));
        arr[arg2 >> 2] = word & mask;
        arg2++;
        i++;
    }
}
