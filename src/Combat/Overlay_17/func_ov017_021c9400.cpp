#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9400 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    unsigned char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short unknown_8_;
    short unknown_a_;
    int unknown_c_;
    int unknown_10_;
};

// USA: func_ov017_021c9400
extern "C" ARM void func_ov017_021c9400(int id, int nibble, int unused, EventVec3 pos, EventVec3 rot, int mode) {
    void* p = LinkMessageQueue_GetInstance();
    LocalEvt021c9400 evt;
    evt.tag = 0x85;
    evt.field4 = id;
    evt.field7lo = (unsigned char)nibble;
    evt.field7 = (signed char)mode;
    evt.fieldC = pos.a;
    evt.fieldA = pos.b >> 4;
    evt.field10 = pos.c;
    evt.field8 = rot.b;
    func_0205e330(p, &evt, 0);
}
