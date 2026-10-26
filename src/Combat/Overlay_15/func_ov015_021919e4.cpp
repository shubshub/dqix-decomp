#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

extern AllocatorUnion g_mainAllocator;
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov015_0218eef0;
extern "C" void func_ov015_0218eef0(struct Struct_ov015_0218eef0* s);

struct Struct_ov015_0218ef7c_2;
struct Struct_ov015_0218ef7c_3;
struct Struct_ov015_0218ef7c;
extern "C" int func_ov015_0218ef7c(struct Struct_ov015_0218ef7c_2* obj, struct Struct_ov015_0218ef7c_3* src, struct Struct_ov015_0218ef7c* p);

extern "C" int func_ov015_0218f27c(void* p, void* q);
extern "C" void func_ov015_0218f0c4(void* p);

struct ListNode021919e4 { void* payload; struct ListNode021919e4* next; };

struct Struct_ov015_021919e4_2 {
    char pad0[0x2c];
    struct ListNode021919e4* list;
};

// USA: func_ov015_021919e4
extern "C" ARM void* func_ov015_021919e4(struct Struct_ov015_021919e4_2* obj, void* p1) {
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
    void* payload = node->payload;

    func_ov015_0218eef0((struct Struct_ov015_0218eef0*)payload);
    int status = func_ov015_0218ef7c((struct Struct_ov015_0218ef7c_2*)payload, (struct Struct_ov015_0218ef7c_3*)obj, (struct Struct_ov015_0218ef7c*)p1);
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

    struct ListNode021919e4** var3 = &obj->list;
    while (*var3 != 0) {
        var3 = &(*var3)->next;
    }
    *var3 = node;
    return node->payload;
}
