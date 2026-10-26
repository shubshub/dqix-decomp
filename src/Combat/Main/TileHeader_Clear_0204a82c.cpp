#include <globaldefs.h>

struct Struct0204a82c {
    int f0;
    short f4;
    short unknown_6_;
    short f8;
    char fa;
};

// Main, originally ClearStruct0204a82c (USA 0x0204a82c, EUR 0x0204a83c, JPN 0x0204b64c)
extern "C" ARM void TileHeader_Clear(struct Struct0204a82c* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->unknown_6_ = 0;
    s->f8 = 0;
    s->fa = 0;
}
