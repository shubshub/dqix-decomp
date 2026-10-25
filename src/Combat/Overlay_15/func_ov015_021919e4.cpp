#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern AllocatorUnion g_mainAllocator;
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov015_0218eef0;
extern "C" void func_ov015_0218eef0(struct Struct_ov015_0218eef0* arg0);

struct Struct_ov015_0218ef7c_2;
struct Struct_ov015_0218ef7c_3;
struct Struct_ov015_0218ef7c;
extern "C" int func_ov015_0218ef7c(struct Struct_ov015_0218ef7c_2* arg0, struct Struct_ov015_0218ef7c_3* arg1, struct Struct_ov015_0218ef7c* arg2);

extern "C" int func_ov015_0218f27c(void* arg0, void* arg1);
extern "C" void func_ov015_0218f0c4(void* arg0);

struct Struct_ov015_021919e4 { void* unknown_0_; struct Struct_ov015_021919e4* unknown_4_; };

struct Struct_ov015_021919e4_2 {
    char unknown_0_[0x2c];
    struct Struct_ov015_021919e4* unknown_2c_;
};

// USA: func_ov015_021919e4
extern "C" ARM void* func_ov015_021919e4(struct Obj021919e4* obj, void* p1) {
    struct ListNode021919e4* node = (struct ListNode021919e4*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 8);
    if (node == 0) {
        return 0;
    }
    node->payload = 0;
    node->next = 0;
    node->payload = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x5c);
    if (node->payload == 0) {
        AllocatorUnion_Free(&g_mainAllocator, node);
        return 0;
    }
    void* var1 = var0->unknown_0_;

    InitCombatFieldStruct0218eef0((struct ResetStruct0218eef0*)payload);
    int status = func_ov015_0218ef7c((struct Obj0218ef7c*)payload, (struct SrcState0218ef7c*)obj, (struct P0218ef7c*)p1);
    if (status == 0) {
        AllocatorUnion_Free(&g_mainAllocator, node->payload);
        node->payload = 0;
        AllocatorUnion_Free(&g_mainAllocator, node);
        return 0;
    }

    if (!func_ov015_0218f27c(payload, p1)) {
        func_ov015_0218f0c4(node->payload);
        AllocatorUnion_Free(&g_mainAllocator, node->payload);
        node->payload = 0;
        AllocatorUnion_Free(&g_mainAllocator, node);
        return 0;
    }

    struct Struct_ov015_021919e4** var3 = &arg0->unknown_2c_;
    while (*var3 != 0) {
        var3 = &(*var3)->unknown_4_;
    }
    *var3 = var0;
    return var0->unknown_0_;
}
