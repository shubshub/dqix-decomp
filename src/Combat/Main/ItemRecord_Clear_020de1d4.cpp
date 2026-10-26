#include <globaldefs.h>

struct StructDE1D4 {
    int a, b, c, d;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// Main, originally InitStruct020de1d4 (USA 0x020de1d4, EUR 0x020de1e4, JPN 0x020dfb50)
extern "C" ARM void ItemRecord_Clear(struct StructDE1D4* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->g = -1;
    p->h = 0;
    p->i = 0;
    p->unknown_10_0_ = 999;
    p->unknown_11_2_ = 999;
}
