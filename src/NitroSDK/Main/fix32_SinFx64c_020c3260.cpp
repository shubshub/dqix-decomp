#include <globaldefs.h>

extern "C" long long func_020c30ac(unsigned int, unsigned int);
extern "C" long long func_020c3194(unsigned int, unsigned int);

// Main, originally func_020c3260 (USA 0x020c3260, EUR 0x020c3270, JPN 0x020c4d2c)
extern "C" ARM long long fix32_SinFx64c(int x) {
    long long m;
    if (x < 0) {
        return -fix32_SinFx64c(-x);
    }
    var0 = (long long)arg0 * 0x145F306DDLL;
    int var1 = (int)(var0 >> 44);
    unsigned long long var2 = (unsigned long long)((var0 >> 12) & 0xFFFFFFFFULL);
    if (var1 & 1) {
        var2 = 0x100000000ULL - var2;
    }
    long long var3;
    if ((var1 + 1) & 2) {
        var3 = func_020c3194((unsigned int)var2, (unsigned int)(var2 >> 32));
    } else {
        var3 = func_020c30ac((unsigned int)var2, (unsigned int)(var2 >> 32));
    }
    if ((var1 & 7) <= 3) {
        return var3;
    }
    return -var3;
}
