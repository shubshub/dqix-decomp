#include <globaldefs.h>

extern "C" void G3_RotateZ(void*);
extern "C" void G3_RotateY(int);
extern "C" void G3_RotateX(int);
extern "C" void func_02047448(void* obj, int val, int param1);

struct Struct_020472e4 {
    char pad[8];
    int val;
};

struct Struct_020472e4_2 {
    int unused0;
    struct Struct_020472e4* field4;
};

struct Struct_020472e4_3 {
    unsigned char unknown_0_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct StructAt020472e4 {
    char pad0[0xc];
    struct Struct_020472e4_2* unknown_c_; // 0xc
    char pad1[0x1c - 0xc - 4];
    int unknown_1c_; // 0x1c
    int unknown_20_; // 0x20
    int unknown_24_; // 0x24
    void* rotX;   // 0x28
    void* rotY;   // 0x2c
    void* transformSrc; // 0x30
    int scaleX; // 0x34
    int scaleY; // 0x38
    int scaleZ; // 0x3c
    char pad2[0x70 - 0x40];
    int unknown_70_; // 0x70
    int unknown_74_; // 0x74
    char pad3[0x82 - 0x78];
    short unknown_82_; // 0x82
    struct Struct_020472e4_3 unknown_84_; // 0x84
};

// USA: func_020472e4
extern "C" ARM void func_020472e4(struct StructAt020472e4* obj, int param1) {
    struct Struct_020472e4_2* entry;
    struct Struct_020472e4* block;
    if (!obj->unknown_84_.unknown_0_0_) return;
    if (!obj->unknown_84_.flag1) return;
    if (obj->unknown_82_ <= 0) return;
    entry = &obj->unknown_c_[obj->unknown_74_];
    block = &entry->field4[obj->unknown_70_];
    *(volatile int*)0x4000444 = 0;
    {
        int var2 = obj->unknown_24_, ty = obj->unknown_20_, tx = obj->unknown_1c_;
        *(volatile int*)0x4000470 = tx;
        *(volatile int*)0x4000470 = ty;
        *(volatile int*)0x4000470 = var2;
    }
    {
        int sz = obj->scaleZ, var6 = obj->scaleY, var7 = obj->scaleX;
        *(volatile int*)0x400046c = var7;
        *(volatile int*)0x400046c = var6;
        *(volatile int*)0x400046c = sz;
    }
    if (obj->transformSrc != NULL) G3_RotateZ(obj->transformSrc);
    if (obj->rotY != NULL) G3_RotateY((int)obj->rotY);
    if (obj->rotX != NULL) G3_RotateX((int)obj->rotX);
    func_02047448(obj, block->val, param1);
    *(volatile int*)0x4000448 = 1;
}
