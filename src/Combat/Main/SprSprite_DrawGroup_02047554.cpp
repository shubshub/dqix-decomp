#include <globaldefs.h>

extern "C" void func_02047718(void* obj, void* entry, int something);

struct Struct_02047554 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char count;
    unsigned char pad3;
    unsigned char* unknown_4_;
};

struct Struct_02047554_2 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char rest : 6;
};

struct Obj02047554 {
    char pad0[0x8];
    struct Struct_02047554* entries;
    char pad1[0x1c - 0x8 - 4];
    int f1c;
    int f20;
    int f24;
    char pad2[0x34 - 0x28];
    int f34;
    int unknown_38_;
    int f3c;
    char pad3[0x82 - 0x40];
    short unknown_82_;
    struct Struct_02047554_2 f84;
};

// Main, originally func_02047554 (USA 0x02047554, EUR 0x02047564, JPN 0x02048374)
extern "C" ARM void SprSprite_DrawGroup(struct Obj02047554* obj, int idx, int something) {
    if (!obj->f84.bit0) return;
    if (!obj->f84.unknown_0_1_) return;
    if (obj->unknown_82_ <= 0) return;

    struct Struct_02047554* entry = obj->entries + idx;
    if (entry->unknown_4_ == 0 || entry->count == 0) return;

    volatile int* reg = (volatile int*)0x4000444;
    *reg = 0;
    *(volatile int*)((char*)reg + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)reg + 0x80) = 0x4210;

    int tx = obj->f1c;
    int ty = obj->f20 + entry->unknown_1_ * obj->unknown_38_;
    int var4 = obj->f24;
    *(volatile int*)((char*)reg + 0x2c) = tx;
    *(volatile int*)((char*)reg + 0x2c) = ty;
    *(volatile int*)((char*)reg + 0x2c) = var4;

    int sz = obj->f3c;
    int var6 = obj->f34;
    int var7 = -obj->unknown_38_;
    *(volatile int*)((char*)reg + 0x28) = var6;
    *(volatile int*)((char*)reg + 0x28) = var7;
    *(volatile int*)((char*)reg + 0x28) = sz;

    unsigned char* p = entry->unknown_4_;
    int i;
    for (i = 0; i < entry->count; ) {
        func_02047718(obj, p, something);
        i++;
        p += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
