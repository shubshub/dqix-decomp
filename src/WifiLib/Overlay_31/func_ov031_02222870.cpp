#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);

// USA: func_ov031_02222870
extern "C" THUMB unsigned int func_ov031_02222870(void) {
    return (unsigned int)_ll_udiv(GetCurrentTimestamp() << 6, 0x82ea);
}
