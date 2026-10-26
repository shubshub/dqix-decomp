#include <globaldefs.h>

// USA: func_ov031_0221e31c
extern "C" THUMB void func_ov031_0221e31c(int, unsigned int* table) {
    unsigned int var0;
    int i;
    int bit;
    i = 0;
    do {
        var0 = i;
        bit = 0;
        do {
            if (var0 & 1) var0 = (var0 >> 1) ^ 0xEDB88320;
            else var0 >>= 1;
            bit++;
        } while (bit < 8);
        *table++ = var0;
        i++;
    } while (i < 256);
}
