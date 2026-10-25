#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Callback0204abcc)(void*, int, int);

struct Obj0204abcc {
    char pad0[2];
    unsigned short field2;
};

struct P0204abcc {
    char pad0[8];
    int field8;
    char field0xc[1];
};

// Main, originally ForEachMaskedChunk0204abcc (USA 0x0204abcc, EUR 0x0204abdc, JPN 0x0204b9ec)
ARM void Background_UploadPalette(struct Obj0204abcc* obj, Callback0204abcc fn, struct P0204abcc* p) {
    int localVal;
    memcpy(&localVal, &p->field8, 4);
    if (obj->field2 == 0xffff) {
        fn(p->field0xc, 0, localVal);
    } else {
        int mask = obj->field2 & 0xff;
        int i;
        for (i = 0; i < 16; i++) {
            if (mask & 1) {
                fn(p->field0xc + i * 32, i * 32, 32);
            }
            mask = (mask >> 1) & 0xff;
        }
    }
}
