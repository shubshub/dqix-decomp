#include <globaldefs.h>

extern "C" void func_02047718(void* obj, void* entry, int something);
extern "C" void G3_RotateY(int);

struct Struct_02047448 {
    unsigned char unknown_0_;
    unsigned char pad1;
    unsigned char count;
    unsigned char pad3;
    unsigned char* unknown_4_;
};

struct Struct_02047448_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct Struct_02047448_3 {
    char pad0[0x8];
    struct Struct_02047448* entries; // 0x8
    char pad1[0x1c - 0x8 - 4];
    int unknown_1c_; // 0x1c
    int unknown_20_; // 0x20
    int unknown_24_; // 0x24
    void* rotX;  // 0x28
    void* rotY;  // 0x2c
    void* transformSrc; // 0x30
    int scaleX; // 0x34
    int scaleY; // 0x38
    int scaleZ; // 0x3c
    char pad2[0x82 - 0x40];
    short unknown_82_; // 0x82
    struct Struct_02047448_2 unknown_84_; // 0x84
};

// USA: func_02047448
extern "C" ARM void func_02047448(struct Struct_02047448_3* obj, int idx, int something) {
    if (!obj->unknown_84_.unknown_0_0_) return;
    if (!obj->unknown_84_.flag1) return;
    if (obj->unknown_82_ <= 0) return;

    struct Struct_02047448* entry = obj->entries + idx;
    if (entry->unknown_4_ == 0 || entry->count == 0) return;

    volatile int* reg = (volatile int*)0x4000444;
    *reg = 0;
    *(volatile int*)((char*)reg + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)reg + 0x80) = 0x4210;

    int tx = obj->unknown_1c_ - (entry->unknown_0_ >> 1) * obj->scaleX;
    int var3 = obj->unknown_24_;
    int ty = obj->unknown_20_;
    *(volatile int*)((char*)reg + 0x2c) = tx;
    *(volatile int*)((char*)reg + 0x2c) = ty;
    *(volatile int*)((char*)reg + 0x2c) = var3;

    G3_RotateY((int)obj->rotY);

    int var5 = obj->scaleX;
    int sz = obj->scaleZ;
    int var7 = obj->scaleY;
    volatile int* var8 = (volatile int*)0x400046c;
    *var8 = var5;
    *var8 = var7;
    *var8 = sz;

    unsigned char* p = entry->unknown_4_;
    int i;
    for (i = 0; i < entry->count; ) {
        func_02047718(obj, p, something);
        i++;
        p += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
