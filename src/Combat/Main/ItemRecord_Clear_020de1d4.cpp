#include <globaldefs.h>

struct StructDE1D4 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// Main, originally InitStruct020de1d4 (USA 0x020de1d4, EUR 0x020de1e4, JPN 0x020dfb50)
ARM void ItemRecord_Clear(struct StructDE1D4* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->g = -1;
    p->h = 0;
    p->i = 0;
    p->field10Low = 999;
    p->field10Mid = 999;
}
