#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_020484f8_3;
struct Struct_020484f8_4;
struct Struct_0203d028_18;

struct Struct_020484f8 {
    char unk0[0x8];
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_020484f8_2 {
    struct Struct_020484f8* ac;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
};

// USA: func_020484f8
extern "C" ARM void func_020484f8(Object3D* arg0, Struct_020484f8_2* in) {
    unsigned char* self = (unsigned char*)arg0;
    *(unsigned int*)(self + 0xb0) = in->unknown_4_;
    *(struct Struct_020484f8**)(self + 0xac) = in->ac;
    *(unsigned int*)(self + 0xb4) = in->unknown_8_;
    ((Object3D*)((struct Struct_0203d028_18*)self))->SetScale(0x10a, 0x10a, 0x10a);
    ((Object3D*)((struct Struct_020484f8_3*)self))->SetRadius((*(struct Struct_020484f8**)(self + 0xac))->unknown_c_ << 2);
    ((Object3D*)((struct Struct_020484f8_4*)self))->SetHeight((*(struct Struct_020484f8**)(self + 0xac))->unknown_e_);
    if ((*(struct Struct_020484f8**)(self + 0xac))->unknown_8_ == 0x140) {
        ((Object3D*)self)->EnableFlag(0x20000000);
    }
    if (((Object3D*)self)->GetFlags() & 0x20000000) return;
    ((Object3D*)self)->UseRenderConfigDiffuseColor();
}
