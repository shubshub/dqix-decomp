#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int memcmp(unsigned char* a, unsigned char* b, int n);
extern "C" void memcpy(void* dst, const void* src, int n);

extern unsigned char data_ov023_021fdc90;

struct Struct_ov023_021e20f0_4 {
    char pad0[4];
    int field4;
    char pad8[0xc - 0x8];
    int fieldC;
    char pad10[0x14 - 0x10];
    int field14;
    int field18;
};

struct Struct_ov023_021e20f0_5 {
    char pad0[8];
    void* arr1;   // 0x8
    void* arr2;   // 0xc
    char pad10[0x14 - 0x10];
    unsigned short count1; // 0x14
    unsigned short sum;    // 0x16
};

struct Struct_ov023_021e20f0_6 {
    char pad0[4];
    int field4;
    short field8;
    short fieldA;
    char unknown_c_[0xe - 0xc];
    unsigned short unknown_e_;
    unsigned short field10;
    unsigned short field12;
    unsigned short field14;
    unsigned short unknown_16_;
    unsigned short field18;
};

struct Struct_ov023_021e20f0_7 {
    signed short field0;
    unsigned short field2;
    void* field4;
    signed short field8;
    signed short fieldA;
    signed short fieldC;
    signed short unknown_e_;
    signed short field10;
    signed short field12;
    unsigned short field14;
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021e20f0 {
    int field0;
    short field4;
    short field6;
    signed short field8;
    char pad8[0x10 - 0xa];
    unsigned short field10;
    unsigned short field12;
};

struct Struct_ov023_021e20f0_2 { unsigned char unknown_0_0_ : 4; unsigned char hiNibble : 4; };

struct Struct_ov023_021e20f0_3 {
    short field0;
    unsigned char field2;
    unsigned char unknown_3_;
    signed short field4;
    signed short field6;
    signed short field8;
    signed short fieldA;
    int fieldC;
    unsigned char field10;
};

// USA: func_ov023_021e20f0
extern "C" ARM int func_ov023_021e20f0(struct Struct_ov023_021e20f0_5* p, SafeAllocator* alloc,
        struct Struct_ov023_021e20f0_4* header, void* arg3) {
    short var0 = -1;
    if (alloc == 0) return 1;
    if (header == 0) return 1;
    if (arg3 == 0) return 1;

    if (memcmp((unsigned char*)((char*)header + 8), &data_ov023_021fdc90, 3) != 0) {
        return 1;
    }

    header->fieldC = (int)((char*)header + header->fieldC);
    header->field14 = (int)((char*)header + header->field14);
    p->count1 = 0;
    p->sum = 0;
    p->count1 = header->field18;
    p->arr1 = alloc->Allocate(p->count1 * 0x18);
    struct Struct_ov023_021e20f0_6* var1 = (struct Struct_ov023_021e20f0_6*)((char*)header + header->field4);
    unsigned short count1 = p->count1;

    unsigned short i;
    for (i = 0; i < count1; i++) {
        struct Struct_ov023_021e20f0_6* src = (struct Struct_ov023_021e20f0_6*)((char*)var1 + i * 0x1c);
        struct Struct_ov023_021e20f0_7* dst = (struct Struct_ov023_021e20f0_7*)((char*)p->arr1 + i * 0x18);

        dst->field0 = var0;
        dst->field2 = 0;
        dst->field4 = 0;
        dst->fieldA = 0;
        dst->field8 = dst->fieldA;
        dst->fieldC = var0;
        dst->unknown_e_ = var0;
        dst->field10 = var0;
        dst->field12 = var0;
        dst->field14 = 0;
        dst->unknown_16_ = 3;
        dst->unknown_17_ = 0xff;

        dst->field8 = src->field8;
        dst->fieldA = src->fieldA;
        dst->field2 = src->unknown_e_;
        dst->field4 = alloc->Allocate(src->unknown_e_ * 2);
        char* var6 = (char*)header->field14 + src->field4;
        if (var6 != 0) {
            memcpy(dst->field4, var6, src->unknown_e_ * 2);
        }
        dst->field0 = src->field10;
        dst->fieldC = src->field12;
        dst->unknown_e_ = src->field14;
        dst->field10 = src->unknown_16_;
        dst->field12 = src->field18;
        p->sum = p->sum + dst->field2;
    }

    p->arr2 = alloc->Allocate(p->sum * 0x14);
    struct Struct_ov023_021e20f0* var7 = (struct Struct_ov023_021e20f0*)header->fieldC;

    unsigned short j;
    for (j = 0; j < p->sum; j++) {
        struct Struct_ov023_021e20f0* var9 = (struct Struct_ov023_021e20f0*)((char*)var7 + j * 0x28);
        struct Struct_ov023_021e20f0_3* var10 = (struct Struct_ov023_021e20f0_3*)((char*)p->arr2 + j * 0x14);

        var10->field0 = -1;
        var10->field2 = 0;
        struct Struct_ov023_021e20f0_2* b3 = (struct Struct_ov023_021e20f0_2*)&var10->unknown_3_;
        b3->unknown_0_0_ = 0xa;
        b3->hiNibble = 0xf;
        var10->field6 = 0;
        var10->field4 = var10->field6;
        var10->fieldA = 0;
        var10->field8 = var10->fieldA;
        var10->fieldC = 0;
        var10->field10 = 0;

        var10->field4 = var9->field4;
        var10->field6 = var9->field6;
        var10->field0 = var9->field8;

        switch (var9->field0) {
        case 0:
            var10->field2 = 2;
            var10->field8 = *(unsigned short*)((char*)var9 + 0xc);
            var10->fieldA = *(unsigned short*)((char*)var9 + 0xe);
            break;
        case 1:
            var10->field2 = 1;
            var10->field8 = *(unsigned short*)((char*)var9 + 0xc);
            var10->fieldA = *(unsigned short*)((char*)var9 + 0xe);
            break;
        case 3:
            if (*(int*)((char*)var9 + 0xc) == 0) {
                var10->field8 = var9->field10;
                var10->fieldA = var9->field12;
            }
            break;
        case 2:
        default:
            break;
        }
    }

    return 0;
}
