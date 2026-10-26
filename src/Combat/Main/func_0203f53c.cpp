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
    unsigned int field_0x0;
    unsigned short material, unknown_6_;
    unsigned char padding[0xc];
    unsigned int flags;
};
struct Struct_0203f53c_2 {
    unsigned char padding[0x10];
    Struct_0203f2b0_2 list;
};
struct Struct_0203f53c_3 {
    unsigned char padding[0x10];
    unsigned int* indices;
};
struct Struct_0203f53c_4 {
    unsigned int field_0x0, unknown_4_;
    int size;
    unsigned int unknown_c_;
};
struct Struct_0203f53c_5 {
    unsigned short width, height, count, unknown_6_;
    Struct_0203f53c_4* records;
};
struct Struct_0203f53c {
    Struct_02040468* list;
    Vector3i position;
    unsigned char unknown_10_[0xc];
    Vector3i scale;
    short unknown_28_;
    unsigned char unknown_2a_[0x44 - 0x2a];
    unsigned int row, column;
    int offset;
    unsigned int flags;
    int angle;
};
union Struct_020e79cc {
    struct { short x, y, z, width, height, depth; } bounds;
    unsigned int words[3];
};
extern "C" Struct_0203f53c_2* func_02040468(Struct_02040468*, int);
extern "C" void* func_0203f1c8(unsigned char*, unsigned int);
extern "C" Struct_0203f53c_5* func_0203f354(Struct_0203f2b0_2*, unsigned int);
extern "C" void* Camera_GetInverseRotation(void*);
extern "C" int func_020c56b0(int*);
extern "C" int Camera_GetOrbitYaw(void*);
extern "C" void func_020c51c0(int);
extern "C" void MI_Copy36B(const void*, void*);
extern "C" void G3_RotateZ(void*);
extern "C" void G3_RotateY(int);
extern "C" void func_0203f98c(Struct_0203f53c*, Struct_0203f53c_4*, int, unsigned int,
    unsigned short, unsigned short, unsigned short);
extern Matrix3x3 data_020e79e8, data_0210a0cc;
extern Vector3i data_020e79c0;
extern Struct_020e79cc data_020e79cc;

static inline int inline_0203f53c(int a, int b) { return FIX32_MULTIPLY(a, b); }

// USA: func_0203f53c
extern "C" ARM int func_0203f53c(Struct_0203f53c* object, void* camera, int scale) {
    if (object->flags & 1) return 0;
    if (object->unknown_28_ < 0) return 0;
    Struct_0203f53c_2* element = func_02040468(object->list, object->unknown_28_);
    if (!element) return 0;
    Struct_0203f53c_3* stride = (Struct_0203f53c_3*)func_0203f1c8((unsigned char*)&element->list, object->row);
    if (!stride) return 0;
    Struct_0203f53c_5* entry = func_0203f354(&element->list, stride->indices[object->column]);
    if (!entry) return 0;
    if (!entry->records) return 0;
    Matrix3x3* view = (Matrix3x3*)Camera_GetInverseRotation(camera);
    int scaleX = inline_0203f53c(object->scale.x, scale);
    int scaleY = inline_0203f53c(object->scale.y, scale);
    int scaleZ = inline_0203f53c(object->scale.z, scale);
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
    Struct_020e79cc box = data_020e79cc;
    box.bounds.y = -height;
    box.bounds.height = height;
    REG_BOX_0203f53c = box.words[0];
    REG_BOX_0203f53c = box.words[1];
    REG_BOX_0203f53c = box.words[2];
    int visible;
    while (func_020c56b0(&visible) != 0) {}
    if (!visible) return 0;
    REG_MATRIX_MODE_0203f53c = 0;
    if (object->flags & 8) {
        int angle = 0x6488 - object->angle;
        if (angle >= 0x6488) angle -= 0x6488;
        int rotationAngle = -(fix32abs(fix32cos(angle)) >> 1);
        if (angle < 0) {
            while (angle * 8 < -0x3244) angle += 0xc91;
            if (angle < 0) angle += 0x6488;
        } else {
            while (angle * 8 >= 0x3244) angle -= 0xc91;
            if (angle < 0) angle += 0x6488;
        }
        int cosine = fix32cos(rotationAngle + 0x6488);
        int sine = fix32sin(rotationAngle + 0x6488);
        Matrix3x3 rotation, transformed;
        Mat3x3_WriteRotationX(&rotation, sine, cosine);
        Mat3x3_Multiply(&rotation, view, &transformed);
        int var19 = inline_0203f53c(entry->height * (scale == 0x1000 ? 0x800 : 0xc00), scaleX);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -var19;
        REG_TRANSLATE_0203f53c = 0;
        func_020c51c0((int)&transformed);
        G3_RotateZ((void*)angle);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = var19;
        REG_TRANSLATE_0203f53c = 0;
    } else {
        int var20 = inline_0203f53c(entry->height * (scale == 0x1000 ? 0x800 : 0xc00), scaleX);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -var20;
        REG_TRANSLATE_0203f53c = 0;
        if (!(object->flags & 0x10)) func_020c51c0((int)view);
        else G3_RotateY(Camera_GetOrbitYaw(camera));
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = var20;
        REG_TRANSLATE_0203f53c = 0;
    }
    REG_TRANSLATE_0203f53c = ((-entry->width) * scaleX) >> 1;
    REG_TRANSLATE_0203f53c = 0;
    REG_TRANSLATE_0203f53c = 0;
    REG_SCALE_0203f53c = scaleX;
    REG_SCALE_0203f53c = -scaleY;
    REG_SCALE_0203f53c = scaleZ;
    int index = 0;
    int offset = object->offset;
    Struct_0203f53c_4* record = entry->records;
    for (; index < entry->count;) {
        func_0203f98c(object, record, offset, element->list.flags,
            element->list.material, entry->width, entry->height);
        ++index;
        offset += record->size;
        ++record;
    }
    REG_MATRIX_POP_0203f53c = 1;
    return 1;
}
