#include <globaldefs.h>
#include "Combat/MapDisplay.h"

struct Struct0204a82c;
ARM void ClearStruct0204a82c(struct Struct0204a82c*);

// Main, originally ResetList0204af64 (USA 0x0204af64, EUR 0x0204af74, JPN 0x0204bd84)
ARM void Background_Init(struct List0204af64* obj) {
    ClearStruct0204a82c((struct Struct0204a82c*)obj);
    obj->b0c = 0;
    obj->h0e = 0xffff;
    obj->w10 = 0;
    obj->w14 = 0;
    obj->w18 = 0;
    obj->b1c_lo = 0;
    obj->b1c_hi = 0;
    obj->b1d = 0;
    obj->b1e = 0;
    obj->b1f = 0;
}
