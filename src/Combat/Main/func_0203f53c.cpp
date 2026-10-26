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
Element_0203f53c* GetValidElement02040468(List02040468*, int);
void* GetElementStride0x14_0203f1c8(unsigned char*, unsigned int);
Entry_0203f53c* GetListElementByIndex(List_0203f354*, unsigned int);
void* Camera_GetInverseRotation(void*);
int GetBoxTestResult_020c56b0(int*);
int Camera_GetOrbitYaw(void*);
extern "C" void func_020c51c0(int);
extern "C" void MI_Copy36B(const void*, void*);
extern "C" void G3_RotateZ(void*);
extern "C" void G3_RotateY(int);
extern "C" void func_0203f98c(Object_0203f53c*, Record_0203f53c*, int, unsigned int,
    unsigned short, unsigned short, unsigned short);
extern Matrix3x3 data_020e79e8, data_0210a0cc;
extern Vector3i data_020e79c0;
extern Struct_020e79cc data_020e79cc;

static inline int inline_0203f53c(int arg0, int arg1) { return FIX32_MULTIPLY(arg0, arg1); }

// USA: func_0203f53c
extern "C" ARM int func_0203f53c(Object_0203f53c* object, void* camera, int scale) {
    if (object->flags & 1) return 0;
    if (object->elementIndex < 0) return 0;
    Element_0203f53c* element = GetValidElement02040468(object->list, object->elementIndex);
    if (!element) return 0;
    Stride_0203f53c* stride = (Stride_0203f53c*)GetElementStride0x14_0203f1c8((unsigned char*)&element->list, object->row);
    if (!stride) return 0;
    Entry_0203f53c* entry = GetListElementByIndex(&element->list, stride->indices[object->column]);
    if (!entry) return 0;
    if (!entry->records) return 0;
    Matrix3x3* view = (Matrix3x3*)Camera_GetInverseRotation(camera);
    int scaleX = MultiplyFix32_0203f53c(object->scale.x, scale);
    int scaleY = MultiplyFix32_0203f53c(object->scale.y, scale);
    int scaleZ = MultiplyFix32_0203f53c(object->scale.z, scale);
    int height = entry->height * scaleY;
    Vector3i position;
    position.x = object->position.x;
    position.y = object->position.y + height;
    position.z = object->position.z;
    RenderConfig::SetObjectPosition(&position);
    Matrix3x3 identity = data_020e79e8;
    MI_Copy36B(&identity, &data_0210a0cc);
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
        func_020c51c0((int)&transformed);
        G3_RotateZ((void*)angle);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = var19;
        REG_TRANSLATE_0203f53c = 0;
    } else {
        int var20 = inline_0203f53c(var2->unknown_2_ * (arg2 == 0x1000 ? 0x800 : 0xc00), var4);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -var20;
        REG_TRANSLATE_0203f53c = 0;
        if (!(object->flags & 0x10)) func_020c51c0((int)view);
        else G3_RotateY(Camera_GetOrbitYaw(camera));
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
