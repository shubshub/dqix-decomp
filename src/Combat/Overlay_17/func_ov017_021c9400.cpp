#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9400 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char field6;
    unsigned char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c9400
extern "C" ARM void func_ov017_021c9400(int id, int nibble, int unused, EventVec3 pos, EventVec3 rot, int mode) {
    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021c9400 evt;
    evt.tag = 0x85;
    evt.field4 = id;
    evt.unknown_7_0_ = (unsigned char)nibble;
    evt.unknown_7_4_ = (signed char)mode;
    evt.fieldC = pos.a;
    evt.fieldA = pos.b >> 4;
    evt.field10 = pos.c;
    evt.field8 = rot.b;
    func_0205e330(p, &evt, 0);
}
