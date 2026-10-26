#include <globaldefs.h>

struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// Main, originally GetPreferredPackedField020de234 (USA 0x020de234, EUR 0x020de244, JPN 0x020dfbb0)
extern "C" ARM unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* p, int preferMid) {
    if (p->g <= 0) {
        return 999;
    }
    if (!preferMid) {
        if (p->unknown_10_0_ != 999) {
            return p->unknown_10_0_;
        }
        return p->unknown_11_2_;
    } else {
        if (p->unknown_11_2_ != 999) {
            return p->unknown_11_2_;
        }
        return p->unknown_10_0_;
    }
}
