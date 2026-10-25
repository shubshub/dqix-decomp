#include <globaldefs.h>

struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// Main, originally GetPreferredPackedField020de234 (USA 0x020de234, EUR 0x020de244, JPN 0x020dfbb0)
ARM unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* p, int preferMid) {
    if (p->g <= 0) {
        return 999;
    }
    if (!preferMid) {
        if (p->field10Low != 999) {
            return p->field10Low;
        }
        return p->field10Mid;
    } else {
        if (p->field10Mid != 999) {
            return p->field10Mid;
        }
        return p->field10Low;
    }
}
