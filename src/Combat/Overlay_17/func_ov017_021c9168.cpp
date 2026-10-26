#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Struct_ov017_021c9168 {
    struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } unknown_0_;
    struct { char unknown_0_0_ : 4; char unknown_0_4_ : 4; } unknown1_0_;
};

struct Struct_ov017_021c9168_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned char unknown_6_[1];
    union Struct_ov017_021c9168 unknown_7_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
};

// USA: func_ov017_021c9168
extern "C" ARM void func_ov017_021c9168(int p0, int p1, int p2, int p3,
        int p4, int p5, int p6, int p7, int p8, int p9, int p10) {
    void* d = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c9168_2 var1;
    var1.unknown_0_ = 0x84;
    var1.unknown_4_ = (unsigned short)arg0;
    var1.unknown_7_.unknown_0_.unknown_0_0_ = (unsigned char)arg1;
    var1.unknown_7_.unknown1_0_.unknown_0_4_ = (char)arg10;
    var1.unknown_c_ = arg4;
    var1.unknown_10_ = arg6;
    var1.unknown_a_ = (unsigned short)arg8;
    var1.unknown_8_ = (unsigned short)arg3;

    func_0205e330(var0, &var1, 0);
}
