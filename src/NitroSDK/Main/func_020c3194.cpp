#include <globaldefs.h>

// USA: func_020c3194
extern "C" ARM long long func_020c3194(unsigned long long arg0) {
    if (arg0 == 0x100000000ULL) {
        return 0xb504f334;
    }
    unsigned long long var0 = (arg0 * arg0) >> 32;
    unsigned long long tmp;
    tmp = 0x100000000ULL - ((var0 * 0x02d1e41dULL) >> 32);
    tmp = 0x100000000ULL - ((tmp * ((var0 * 0x054387adULL) >> 32)) >> 32);
    tmp = 0x100000000ULL - ((tmp * ((var0 * 0x0d28d331ULL) >> 32)) >> 32);
    return 0x100000000ULL - ((tmp * ((var0 * 0x4ef4f327ULL) >> 32)) >> 32);
}
