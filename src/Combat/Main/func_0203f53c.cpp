#include <globaldefs.h>
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"

#if defined(jpn)
#define func_020c51c0 func_020c6c8c
#endif

#define REG_BOX_0203f53c (*(volatile unsigned int*)0x040005c0)
#define REG_MATRIX_MODE_0203f53c (*(volatile int*)0x04000444)
#define REG_TRANSLATE_0203f53c (*(volatile int*)0x04000470)
#define REG_SCALE_0203f53c (*(volatile int*)0x0400046c)
#define REG_MATRIX_POP_0203f53c (*(volatile int*)0x04000448)

struct Struct_02040468;
struct Struct_0203f2b0_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_, unknown_6_;
    unsigned char unknown_8_[0xc];
    unsigned int unknown_14_;
};
struct Struct_0203f53c_2 {
    unsigned char unknown_0_[0x10];
    Struct_0203f2b0_2 unknown_10_;
};
struct Struct_0203f53c_3 {
    unsigned char unknown_0_[0x10];
    unsigned int* unknown_10_;
};
struct Struct_0203f53c_4 {
    unsigned int unknown_0_, unknown_4_;
    int unknown_8_;
    unsigned int unknown_c_;
};
struct Struct_0203f53c_5 {
    unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_;
    Struct_0203f53c_4* unknown_8_;
};
struct Struct_0203f53c {
    Struct_02040468* unknown_0_;
    Vector3i unknown_4_;
    unsigned char unknown_10_[0xc];
    Vector3i unknown_1c_;
    short unknown_28_;
    unsigned char unknown_2a_[0x44 - 0x2a];
    unsigned int unknown_44_, unknown_48_;
    int unknown_4c_;
    unsigned int unknown_50_;
    int unknown_54_;
};
union Struct_020e79cc {
    struct { short unknown_0_, unknown_2_, unknown_4_, unknown_6_, unknown_8_, unknown_a_; } unknown_0_;
    unsigned int unknown1_0_[3];
};
extern "C" Struct_0203f53c_2* func_02040468(Struct_02040468*, int);
extern "C" void* func_0203f1c8(unsigned char*, unsigned int);
extern "C" Struct_0203f53c_5* func_0203f354(Struct_0203f2b0_2*, unsigned int);
extern "C" void* func_0202ed74(void*);
extern "C" int func_020c56b0(int*);
extern "C" int func_0202e7f0(void*);
extern "C" void func_020c51c0(int);
extern "C" void func_020ca528(const void*, void*);
extern "C" void func_02031278(void*);
extern "C" void G3_RotateY(int);
extern "C" void func_0203f98c(Object_0203f53c*, Record_0203f53c*, int, unsigned int,
    unsigned short, unsigned short, unsigned short);
extern Matrix3x3 data_020e79e8, data_0210a0cc;
extern Vector3i data_020e79c0;
extern Struct_020e79cc data_020e79cc;

static inline int inline_0203f53c(int arg0, int arg1) { return FIX32_MULTIPLY(arg0, arg1); }

// USA: func_0203f53c
extern "C" ARM int func_0203f53c(Struct_0203f53c* arg0, void* arg1, int arg2) {
    if (arg0->unknown_50_ & 1) return 0;
    if (arg0->unknown_28_ < 0) return 0;
    Struct_0203f53c_2* var0 = func_02040468(arg0->unknown_0_, arg0->unknown_28_);
    if (!var0) return 0;
    Struct_0203f53c_3* var1 = (Struct_0203f53c_3*)func_0203f1c8((unsigned char*)&var0->unknown_10_, arg0->unknown_44_);
    if (!var1) return 0;
    Struct_0203f53c_5* var2 = func_0203f354(&var0->unknown_10_, var1->unknown_10_[arg0->unknown_48_]);
    if (!var2) return 0;
    if (!var2->unknown_8_) return 0;
    Matrix3x3* var3 = (Matrix3x3*)func_0202ed74(arg1);
    int var4 = inline_0203f53c(arg0->unknown_1c_.x, arg2);
    int var5 = inline_0203f53c(arg0->unknown_1c_.y, arg2);
    int var6 = inline_0203f53c(arg0->unknown_1c_.z, arg2);
    int var7 = var2->unknown_2_ * var5;
    Vector3i var8;
    var8.x = arg0->unknown_4_.x;
    var8.y = arg0->unknown_4_.y + var7;
    var8.z = arg0->unknown_4_.z;
    RenderConfig::SetObjectPosition(&var8);
    Matrix3x3 var9 = data_020e79e8;
    func_020ca528(&var9, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    Vector3i var10 = data_020e79c0;
    RenderConfig::SetObjectScale(&var10);
    RenderConfig::SubmitToFifo();
    Struct_020e79cc var11 = data_020e79cc;
    var11.unknown_0_.unknown_2_ = -var7;
    var11.unknown_0_.unknown_8_ = var7;
    REG_BOX_0203f53c = var11.unknown1_0_[0];
    REG_BOX_0203f53c = var11.unknown1_0_[1];
    REG_BOX_0203f53c = var11.unknown1_0_[2];
    int var12;
    while (func_020c56b0(&var12) != 0) {}
    if (!var12) return 0;
    REG_MATRIX_MODE_0203f53c = 0;
    if (arg0->unknown_50_ & 8) {
        int var13 = 0x6488 - arg0->unknown_54_;
        if (var13 >= 0x6488) var13 -= 0x6488;
        int var14 = -(fix32abs(fix32cos(var13)) >> 1);
        if (var13 < 0) {
            while (var13 * 8 < -0x3244) var13 += 0xc91;
            if (var13 < 0) var13 += 0x6488;
        } else {
            while (var13 * 8 >= 0x3244) var13 -= 0xc91;
            if (var13 < 0) var13 += 0x6488;
        }
        int var15 = fix32cos(var14 + 0x6488);
        int var16 = fix32sin(var14 + 0x6488);
        Matrix3x3 var17, var18;
        Mat3x3_WriteRotationX(&var17, var16, var15);
        Mat3x3_Multiply(&var17, var3, &var18);
        int var19 = inline_0203f53c(var2->unknown_2_ * (arg2 == 0x1000 ? 0x800 : 0xc00), var4);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -var19;
        REG_TRANSLATE_0203f53c = 0;
        func_020c51c0((int)&var18);
        func_02031278((void*)var13);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = var19;
        REG_TRANSLATE_0203f53c = 0;
    } else {
        int var20 = inline_0203f53c(var2->unknown_2_ * (arg2 == 0x1000 ? 0x800 : 0xc00), var4);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -var20;
        REG_TRANSLATE_0203f53c = 0;
        if (!(object->flags & 0x10)) func_020c51c0((int)view);
        else G3_RotateY(GetField0x70_0202e7f0(camera));
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = var20;
        REG_TRANSLATE_0203f53c = 0;
    }
    REG_TRANSLATE_0203f53c = ((-var2->unknown_0_) * var4) >> 1;
    REG_TRANSLATE_0203f53c = 0;
    REG_TRANSLATE_0203f53c = 0;
    REG_SCALE_0203f53c = var4;
    REG_SCALE_0203f53c = -var5;
    REG_SCALE_0203f53c = var6;
    int var21 = 0;
    int var22 = arg0->unknown_4c_;
    Struct_0203f53c_4* var23 = var2->unknown_8_;
    for (; var21 < var2->unknown_4_;) {
        func_0203f98c(arg0, var23, var22, var0->unknown_10_.unknown_14_,
            var0->unknown_10_.unknown_4_, var2->unknown_0_, var2->unknown_2_);
        ++var21;
        var22 += var23->unknown_8_;
        ++var23;
    }
    REG_MATRIX_POP_0203f53c = 1;
    return 1;
}
