#include <globaldefs.h>

extern "C" void func_02031278(void*);
extern "C" void G3_RotateY(int);
extern "C" void func_020311f0(int);
extern "C" void func_02047448(void* obj, int val, int param1);

struct Block020472e4 {
    char pad[8];
    int val;
};

struct ArrEntry020472e4 {
    int unused0;
    struct Block020472e4* field4;
};

struct Flags020472e4 {
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char rest : 6;
};

struct StructAt020472e4 {
    char pad0[0xc];
    struct ArrEntry020472e4* arrayPtr; // 0xc
    char pad1[0x1c - 0xc - 4];
    int transX; // 0x1c
    int transY; // 0x20
    int transZ; // 0x24
    void* rotX;   // 0x28
    void* rotY;   // 0x2c
    void* transformSrc; // 0x30
    int scaleX; // 0x34
    int scaleY; // 0x38
    int scaleZ; // 0x3c
    char pad2[0x70 - 0x40];
    int idx70; // 0x70
    int idx74; // 0x74
    char pad3[0x82 - 0x78];
    short field82; // 0x82
    struct Flags020472e4 field84; // 0x84
};

// USA: func_020472e4
ARM void RenderTransformedFlaggedIndexedEntry(struct StructAt020472e4* obj, int param1) {
    struct ArrEntry020472e4* entry;
    struct Block020472e4* block;
    if (!obj->field84.flag0) return;
    if (!obj->field84.flag1) return;
    if (obj->field82 <= 0) return;
    entry = &obj->arrayPtr[obj->idx74];
    block = &entry->field4[obj->idx70];
    *(volatile int*)0x4000444 = 0;
    {
        int tz = obj->transZ, ty = obj->transY, tx = obj->transX;
        *(volatile int*)0x4000470 = tx;
        *(volatile int*)0x4000470 = ty;
        *(volatile int*)0x4000470 = tz;
    }
    {
        int sz = obj->scaleZ, sy = obj->scaleY, sx = obj->scaleX;
        *(volatile int*)0x400046c = sx;
        *(volatile int*)0x400046c = sy;
        *(volatile int*)0x400046c = sz;
    }
    if (obj->transformSrc != NULL) func_02031278(obj->transformSrc);
    if (obj->rotY != NULL) G3_RotateY((int)obj->rotY);
    if (obj->rotX != NULL) func_020311f0((int)obj->rotX);
    func_02047448(obj, block->val, param1);
    *(volatile int*)0x4000448 = 1;
}
