#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Struct_ov017_021c927c {
    struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } unknown_0_;
    struct { char unknown_0_0_ : 4; char unknown_0_4_ : 4; } unknown1_0_;
};

struct Struct_ov017_021c927c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned char unknown_6_0_ : 6;
    unsigned char unknown_6_6_ : 2;
    union Struct_ov017_021c927c unknown_7_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    int unknown_c_;
    int unknown_10_;
};

// USA: func_ov017_021c927c
extern "C" ARM void func_ov017_021c927c(int id, int slot, int heading, EventVec3 pos, int height, unsigned short mode, int dir) {
    void* d = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c927c_2 var1;
    var1.unknown_0_ = 0x88;
    var1.unknown_4_ = (unsigned short)arg0;
    var1.unknown_7_.unknown_0_.unknown_0_0_ = (unsigned char)arg1;
    var1.unknown_7_.unknown1_0_.unknown_0_4_ = (char)arg6;
    var1.unknown_6_0_ = arg5;
    var1.unknown_c_ = arg3.unknown_0_;
    var1.unknown_a_ = arg3.unknown_4_ >> 4;
    var1.unknown_10_ = arg3.unknown_8_;
    var1.unknown_8_ = (unsigned short)arg4;

    func_0205e330(var0, &var1, 0);
}
