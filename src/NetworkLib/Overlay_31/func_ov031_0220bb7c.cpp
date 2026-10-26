#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb24(unsigned short* arr, int len);

// USA: func_ov031_0220bb7c
extern "C" ARM void func_ov031_0220bb7c(unsigned short* dst, unsigned short* a, unsigned short* b, int len) {
    int var0 = func_ov031_0220bb24(a, len);
    int var1 = func_ov031_0220bb24(b, len);
    int n = var0;
    if (n < var1)
        n = var1;
    if (n != len)
        n = n + 1;
    int i;
    unsigned int var4;
    var4 = 0;
    i = 0;
    if (n > 0) {
        do {
            unsigned int sum = a[i] + b[i] + var4;
            dst[i] = (unsigned short)sum;
            var4 = sum >> 16;
        } while (++i < n);
    }
    if (dst == a || dst == b)
        return;
    VectorizedMemset(dst + i, 0, (len - i) * 2);
}
