#include <globaldefs.h>

extern "C" void func_02047718(void* obj, void* entry, int something);
extern "C" void G3_RotateY(int);

struct Entry02047448 {
    unsigned char byteAt0;
    unsigned char pad1;
    unsigned char count;
    unsigned char pad3;
    unsigned char* arrayPtr;
};

struct Flags02047448 {
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct StructAt02047448 {
    char pad0[0x8];
    struct Entry02047448* entries; // 0x8
    char pad1[0x1c - 0x8 - 4];
    int transX; // 0x1c
    int transY; // 0x20
    int transZ; // 0x24
    void* rotX;  // 0x28
    void* rotY;  // 0x2c
    void* transformSrc; // 0x30
    int scaleX; // 0x34
    int scaleY; // 0x38
    int scaleZ; // 0x3c
    char pad2[0x82 - 0x40];
    short field82; // 0x82
    struct Flags02047448 field84; // 0x84
};

// USA: func_02047448  (semantic: SubmitTransformedGxCommands_02047448)
extern "C" ARM void func_02047448(struct StructAt02047448* obj, int idx, int something) {
    if (!obj->field84.flag0) return;
    if (!obj->field84.flag1) return;
    if (obj->field82 <= 0) return;

    struct Entry02047448* entry = obj->entries + idx;
    if (entry->arrayPtr == 0 || entry->count == 0) return;

    volatile int* reg = (volatile int*)0x4000444;
    *reg = 0;
    *(volatile int*)((char*)reg + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)reg + 0x80) = 0x4210;

    int tx = obj->transX - (entry->byteAt0 >> 1) * obj->scaleX;
    int tz = obj->transZ;
    int ty = obj->transY;
    *(volatile int*)((char*)reg + 0x2c) = tx;
    *(volatile int*)((char*)reg + 0x2c) = ty;
    *(volatile int*)((char*)reg + 0x2c) = tz;

    G3_RotateY((int)obj->rotY);

    int sx = obj->scaleX;
    int sz = obj->scaleZ;
    int sy = obj->scaleY;
    volatile int* reg2 = (volatile int*)0x400046c;
    *reg2 = sx;
    *reg2 = sy;
    *reg2 = sz;

    unsigned char* p = entry->arrayPtr;
    int i;
    for (i = 0; i < entry->count; ) {
        func_02047718(obj, p, something);
        i++;
        p += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
