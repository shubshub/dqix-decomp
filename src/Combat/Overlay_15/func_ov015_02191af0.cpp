#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_ov015_0218f0c4(void* p);
extern "C" void func_ov015_02192700(void* obj, int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct Struct_ov015_02191af0 { void* payload; Struct_ov015_02191af0* next; };

struct Struct_ov015_02191af0_2 {
    char pad0[0x2c];
    Struct_ov015_02191af0* list;
    char pad1[0x23c];
    short counter;
    char pad2[0xb0];
    unsigned short total;
};

// USA: func_ov015_02191af0
extern "C" ARM void func_ov015_02191af0(Struct_ov015_02191af0_2* obj, int count) {
    Struct_ov015_02191af0* cur = obj->list;
    if (cur == 0) {
        return;
    }
    int i = 0;
    Struct_ov015_02191af0* prev = 0;
    Struct_ov015_02191af0* var3 = cur->next;
    while (i < count) {
        prev = cur;
        cur = var3;
        var3 = var3->next;
        i++;
    }
    func_ov015_0218f0c4(cur->payload);
    AllocatorUnion_Free(&g_mainAllocator, cur->payload);
    AllocatorUnion_Free(&g_mainAllocator, cur);
    if (prev != 0) {
        prev->next = var3;
    } else {
        obj->list = var3;
    }
    if ((obj->total - 1) <= obj->counter) {
        obj->counter = obj->total - 2;
        if (obj->counter < 0) {
            obj->counter = 0;
        }
    }
    func_ov015_02192700(obj, 0);
}
