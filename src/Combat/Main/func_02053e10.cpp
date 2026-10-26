#include <globaldefs.h>
#include "Graphics/Model3D.h"

#if defined(jpn)
enum { kFlagsOffset = 0x194 };
#else
enum { kFlagsOffset = 0x1a0 };
#endif

struct Struct_0204a4ac_3;

extern char data_020f048a;
extern char data_020f048f;
extern char data_020f0495;
extern char data_020f049b;
extern char data_020f04a1;
extern char data_020f04a7;
extern char data_020f04ad;

struct Struct_02053e10 {
    char pad0[0x8];
    struct Struct_0204a4ac_3* field8;
    char pad1[kFlagsOffset - 0xc];
    unsigned char unknown_1a0_;
    unsigned char unknown_1a1_;
    unsigned char unknown_1a2_;
    unsigned char unknown_1a3_;
    unsigned char unknown_1a4_;
    unsigned char unknown_1a5_;
    unsigned char unknown_1a6_;
};

// USA: func_02053e10
extern "C" ARM void func_02053e10(struct Struct_02053e10* self) {
    struct Struct_0204a4ac_3* obj = self->field8;
    if (obj == NULL)
        return;
    self->unknown_1a0_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f048a);
    self->unknown_1a1_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f048f);
    self->unknown_1a2_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f0495);
    self->unknown_1a3_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f049b);
    self->unknown_1a4_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f04a1);
    self->unknown_1a5_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f04a7);
    self->unknown_1a6_ = (unsigned char)((Model3D*)obj)->GetBoneIndex(&data_020f04ad);
}
