#include <globaldefs.h>

extern "C" ARM double _dadd(double a, double b);
extern "C" ARM double _ddiv(double a, double b);
extern "C" ARM double func_02008f3c(double x);
extern "C" ARM double func_02008848(double x);

// USA: func_02005ac4
#pragma optimize_for_size off
extern "C" ARM double func_02005ac4(double y, double x) {
    int var0 = ((int*)&x)[1];
    int var1 = var0 & 0x7fffffff;
    unsigned var2 = ((unsigned*)&x)[0];
    int var3 = ((int*)&y)[1];
    int var4 = var3 & 0x7fffffff;
    unsigned var5 = ((unsigned*)&y)[0];

    if (((var1 | ((var2 | -var2) >> 31)) > 0x7ff00000) ||
        ((var4 | ((var5 | -var5) >> 31)) > 0x7ff00000)) {
        return _dadd(x, y);
    }
    if (((var0 - 0x3ff00000) | (int)var2) == 0) return func_02008848(y);

    int m = ((var3 >> 31) & 1) | ((var0 >> 30) & 2);

    if ((var4 | var5) == 0) {
        switch (m) {
            case 0:
            case 1: return y;
            case 2: return 3.1415926535897931160e+00 + 1.0e-300;
            case 3: return -3.1415926535897931160e+00 - 1.0e-300;
        }
    }
    if ((var1 | var2) == 0) {
        return (var3 < 0) ? -1.5707963267948965580e+00 - 1.0e-300
                         : 1.5707963267948965580e+00 + 1.0e-300;
    }

    if (var1 == 0x7ff00000) {
        if (var4 == 0x7ff00000) {
            switch (m) {
                case 0: return 7.8539816339744827900e-01 + 1.0e-300;
                case 1: return -7.8539816339744827900e-01 - 1.0e-300;
                case 2: return 3.0 * 7.8539816339744827900e-01 + 1.0e-300;
                case 3: return -3.0 * 7.8539816339744827900e-01 - 1.0e-300;
            }
        } else {
            switch (m) {
                case 0: return 0.0;
                case 1: return -0.0;
                case 2: return 3.1415926535897931160e+00 + 1.0e-300;
                case 3: return -3.1415926535897931160e+00 - 1.0e-300;
            }
        }
    }
    if (var4 == 0x7ff00000) {
        return (var3 < 0) ? -1.5707963267948965580e+00 - 1.0e-300
                         : 1.5707963267948965580e+00 + 1.0e-300;
    }

    int k = (var4 - var1) >> 20;
    double z;
    if (k > 60) {
        z = 1.5707963267948965580e+00 + 0.5 * 1.2246467991473531772e-16;
    } else if (var0 < 0 && k < -60) {
        z = 0.0;
    } else {
        z = func_02008848(func_02008f3c(_ddiv(y, x)));
    }

    switch (m) {
        case 0: return z;
        case 1: {
            ((int*)&z)[1] = ((int*)&z)[1] ^ 0x80000000;
            return z;
        }
        case 2: return ((3.1415926535897931160e+00) - (((z) - (1.2246467991473531772e-16))));
        default: return ((((z) - (1.2246467991473531772e-16))) - (3.1415926535897931160e+00));
    }
}
#pragma optimize_for_size reset
