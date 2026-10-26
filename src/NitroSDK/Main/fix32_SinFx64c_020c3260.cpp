#include <globaldefs.h>

extern "C" long long func_020c30ac(unsigned int, unsigned int);
extern "C" long long func_020c3194(unsigned int, unsigned int);

// Main, originally func_020c3260 (USA 0x020c3260, EUR 0x020c3270, JPN 0x020c4d2c)
extern "C" ARM long long fix32_SinFx64c(int x) {
    long long m;
    if (x < 0) {
        return -fix32_SinFx64c(-x);
    }
    m = (long long)x * 0x145F306DDLL;
    int hi = (int)(m >> 44);
    unsigned long long v = (unsigned long long)((m >> 12) & 0xFFFFFFFFULL);
    if (hi & 1) {
        v = 0x100000000ULL - v;
    }
    long long r;
    if ((hi + 1) & 2) {
        r = func_020c3194((unsigned int)v, (unsigned int)(v >> 32));
    } else {
        r = func_020c30ac((unsigned int)v, (unsigned int)(v >> 32));
    }
    if ((hi & 7) <= 3) {
        return r;
    }
    return -r;
}
