#include <globaldefs.h>

static const double huge = 1.0e300;

// USA: func_02008f5c
extern "C" ARM double func_02008f5c(double x) {
    int var0, i1, var2;
    unsigned int i, j;
    var0 = ((int*)&x)[1];
    i1 = ((int*)&x)[0];
    var2 = ((var0 >> 20) & 0x7ff) - 0x3ff;
    if (var2 < 20) {
        if (var2 < 0) {
            if (huge + x > 0.0) {
                if (var0 >= 0) {
                    var0 = i1 = 0;
                } else if (((var0 & 0x7fffffff) | i1) != 0) {
                    var0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> var2;
            if (((var0 & i) | i1) == 0) {
                return x;
            }
            if (huge + x > 0.0) {
                if (var0 < 0) {
                    var0 += (0x00100000) >> var2;
                }
                var0 &= (~i);
                i1 = 0;
            }
        }
    } else if (var2 > 51) {
        if (var2 == 0x400) {
            return x + x;
        } else {
            return x;
        }
    } else {
        i = ((unsigned int)(0xffffffff)) >> (var2 - 20);
        if ((i1 & i) == 0) {
            return x;
        }
        if (huge + x > 0.0) {
            if (var0 < 0) {
                if (var2 == 20) {
                    var0 += 1;
                } else {
                    j = i1 + (1 << (52 - var2));
                    if (j < i1) {
                        var0 += 1;
                    }
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    ((int*)&x)[1] = var0;
    ((int*)&x)[0] = i1;
    return x;
}
