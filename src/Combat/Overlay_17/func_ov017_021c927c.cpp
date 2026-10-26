#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Struct_ov017_021c927c {
    struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } lo;
    struct { char unknown_0_0_ : 4; char unknown_0_4_ : 4; } hi;
};

struct Struct_ov017_021c927c_2 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char mode : 6;
    unsigned char pad6 : 2;
    union Struct_ov017_021c927c payload;
    unsigned short field8;
    unsigned short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c927c
extern "C" ARM void func_ov017_021c927c(int id, int slot, int heading, EventVec3 pos, int height, unsigned short mode, int dir) {
    void* d = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c927c_2 evt;
    evt.tag = 0x88;
    evt.field4 = (unsigned short)id;
    evt.payload.lo.unknown_0_0_ = (unsigned char)slot;
    evt.payload.hi.unknown_0_4_ = (char)dir;
    evt.mode = mode;
    evt.fieldC = pos.a;
    evt.fieldA = pos.b >> 4;
    evt.field10 = pos.c;
    evt.field8 = (unsigned short)height;

    func_0205e330(d, &evt, 0);
}
