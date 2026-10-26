#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb24(unsigned short*, int);

// USA: func_ov031_0220bcbc
extern "C" ARM void func_ov031_0220bcbc(unsigned short* destination, unsigned short* left, unsigned short* right, int length) {
    int var0 = func_ov031_0220bb24(left, length);
    int var1 = func_ov031_0220bb24(right, length);
    int limit = var0;
    if (limit < var1) limit = var1;
    int i;
    int var4;
    if (limit != length) limit++;
    i = var4 = 0;
    while (i < limit || (i < length && var4 != 0)) {
        int difference = left[i] - right[i] + var4;
        destination[i] = difference;
        var4 = difference >> 16;
        i++;
    }
    if (destination == left || destination == right) return;
    VectorizedMemset(destination + i, 0, (length - i) * 2);
}
