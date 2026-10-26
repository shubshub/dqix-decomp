#include <globaldefs.h>

#include "std_library_functions.h"

// USA: func_0206dfe8
extern "C" ARM void func_0206dfe8(void *receiver, int first, int second) {
    int var0  = first / 8 + 1;
    int var1 = 8 - first % 8;
    int remaining  = second - var1;
    int var3 = remaining / 8;
    int var4  = remaining % 8;
    if (var3 > 0) {
        memset((unsigned char *) receiver + 0x8c + var0, 0, var3);
    }
    int var5         = var0 + var3;
    unsigned char *bits = (unsigned char *) receiver + 0x8c;
    bits[var5] >>= var4;
    bits[var5] <<= var4;
    bits[var0 - 1] <<= var1;
    bits[var0 - 1] >>= var1;
}
