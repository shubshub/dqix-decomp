#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void VramState_Reserve(void* dst, int a, int b);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov015_02192600 { int f0; int f1; int f2; int f3; };
struct Struct_ov015_02193e48 { struct Struct_ov015_02192600 rows[10]; };
extern struct Struct_ov015_02193e48 data_ov015_02193e48;

struct Struct_ov015_02192600_2 { void* p; int pad4; };

struct Struct_ov015_02192600_3 {
    char pad0[0xc4];
    struct Struct_ov015_02192600_2 arrC4[4];
    struct Struct_ov015_02192600_2 arrE4[4];
    struct Struct_ov015_02192600_2 arr104[4];
};

// USA: func_ov015_02192600
extern "C" ARM void func_ov015_02192600(struct Struct_ov015_02192600_3* obj) {
    struct Struct_ov015_02193e48 local = data_ov015_02193e48;
    int k;
    for (k = 0; k < 4; k++) {
        obj->arrC4[k].p = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x460);
        obj->arrE4[k].p = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x460);
        obj->arr104[k].p = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x70);
        int j;
        for (j = 0; j < 10; j++) {
            VramState_Reserve((char*)obj->arrC4[k].p + j * 0x70, local.rows[j].f0, local.rows[j].f1);
            VramState_Reserve((char*)obj->arrE4[k].p + j * 0x70, local.rows[j].f2, local.rows[j].f3);
        }
        VramState_Reserve(obj->arr104[k].p, 0x4000, 0x400);
    }
    VramState_Reserve((char*)obj + 0x124, 0x4000, 0x40);
}
