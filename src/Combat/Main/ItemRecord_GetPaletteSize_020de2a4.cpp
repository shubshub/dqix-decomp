#include <globaldefs.h>

struct Data020de2a4 {
    unsigned int b0 : 11;    /* bits 0..10  */
    unsigned int f11 : 4;    /* bits 11..14 */
    unsigned int f15 : 4;    /* bits 15..18 */
    unsigned int f19 : 4;    /* bits 19..22 */
    unsigned int f23 : 4;    /* bits 23..26 */
    unsigned int rest : 5;   /* bits 27..31 */
};

struct Obj020de2a4 {
    struct Data020de2a4* data;   /* 0x0 */
    unsigned int _pad4;          /* 0x4 */
    unsigned int type : 4;       /* 0x8 low nibble */
    unsigned int _rest8 : 28;
};

// Main, originally GetNibbleField020de2a4 (USA 0x020de2a4, EUR 0x020de2b4, JPN 0x020dfc20)
ARM int ItemRecord_GetPaletteSize(struct Obj020de2a4* obj, int a, int b) {
    unsigned int t;
    int ok;
    struct Data020de2a4* d;

    t = obj->type;
    ok = t <= 7;
    if (!ok && t != 0xB) return 0;
    d = obj->data;
    if (d == NULL) return 0;
    if (b != 0) {
        if (a != 0) return d->f23;
        return d->f19;
    }
    if (a != 0) return d->f15;
    return d->f11;
}
