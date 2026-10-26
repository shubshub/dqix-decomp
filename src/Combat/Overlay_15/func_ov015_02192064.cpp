#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov015_02190d7c;
extern "C" void func_ov015_021931b4(struct Struct_ov015_02190d7c* s, int v);
extern "C" void func_ov015_02192700(void* obj, int a1);
extern "C" void func_ov015_0218f0c4(void* p);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov015_02190d7c_2;
extern "C" int func_ov015_021931cc(struct Struct_ov015_02190d7c_2* obj);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov015_02192064 { void* value; struct Struct_ov015_02192064* next; };

struct Struct_ov015_02192064_2 {
    char pad0[0x2c];
    struct Struct_ov015_02192064* list;
    void* unknown_30_;
    int field34;
    unsigned char field38;
    char pad39[0x1a4 - 0x39];
    int field1a4;
    char unknown_1a8_[0x2b0 - 0x1a4 - 4];
    short unknown_2b0_;
};

// USA: func_ov015_02192064
extern "C" ARM void func_ov015_02192064(struct Struct_ov015_02192064_2* obj, int mode) {
    int key = obj->field34;
    if (key == 0) {
        return;
    }
    switch (mode) {
    case 0: {
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)obj, obj->field1a4);
        obj->field1a4 = 0x27;
        func_ov015_02192700(obj, 0);
        return;
    }
    case 1: {
        struct Struct_ov015_02192064* node = obj->list;
        struct Struct_ov015_02192064* prev = 0;
        while (node != 0) {
            if ((int)node->value == key) {
                break;
            }
            prev = node;
            node = node->next;
        }

        if (node != 0) {
            struct Struct_ov015_02192064* next = node->next;
            func_ov015_0218f0c4(node->value);
            AllocatorUnion_Free(&g_mainAllocator, node->value);
            AllocatorUnion_Free(&g_mainAllocator, node);
            if (prev != 0) {
                prev->next = next;
            } else {
                obj->list = next;
            }
            if (obj->field34 == (int)obj->unknown_30_) {
                obj->field38 = *((unsigned char*)obj->unknown_30_ + 0x1c);
                obj->unknown_30_ = 0;
            }
            obj->field34 = 0;
        }

        obj->unknown_2b0_ = 0;
        obj->field1a4 = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)obj);
        func_ov015_02192700(obj, 0);
        break;
    }
    }
}
