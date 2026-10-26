#include <globaldefs.h>

// USA: func_020c30ac
extern "C" ARM unsigned long long func_020c30ac(unsigned long long x) {
    if (x == 0x100000000ULL) {
        return 0xB504F334ULL;
    }
    unsigned long long x2 = (x * x) >> 32;
    unsigned long long t;
    t = 0x100000000ULL - ((x2 * 0x02317888ULL) >> 32);
    t = 0x100000000ULL - ((t * ((x2 * 0x03C2857CULL) >> 32)) >> 32);
    t = 0x100000000ULL - ((t * ((x2 * 0x07E54B84ULL) >> 32)) >> 32);
    t = 0xC90FDAA2ULL - ((t * ((x2 * 0x14ABBCE6ULL) >> 32)) >> 32);
    return (t * x) >> 32;
}
