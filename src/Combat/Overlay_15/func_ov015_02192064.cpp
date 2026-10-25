#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct021931b4;
void PushArrayValue021931b4(struct Struct021931b4* s, int v);
extern "C" void func_ov015_02192700(void* obj, int a1);
extern "C" void func_ov015_0218f0c4(void* p);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov015_02190d7c_2;
extern "C" int func_ov015_021931cc(struct Struct_ov015_02190d7c_2* arg0);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov015_02192064 { void* unknown_0_; struct Struct_ov015_02192064* unknown_4_; };

struct Struct_ov015_02192064_2 {
    char unknown_0_[0x2c];
    struct Struct_ov015_02192064* unknown_2c_;
    void* unknown_30_;
    int unknown_34_;
    unsigned char unknown_38_;
    char unknown_39_[0x1a4 - 0x39];
    int unknown_1a4_;
    char unknown_1a8_[0x2b0 - 0x1a4 - 4];
    short unknown_2b0_;
};

// USA: func_ov015_02192064
extern "C" ARM void func_ov015_02192064(struct Struct_ov015_02192064_2* arg0, int arg1) {
    int var0 = arg0->unknown_34_;
    if (var0 == 0) {
        return;
    }
    switch (arg1) {
    case 0: {
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)arg0, arg0->unknown_1a4_);
        arg0->unknown_1a4_ = 0x27;
        func_ov015_02192700(arg0, 0);
        return;
    }
    case 1: {
        struct Struct_ov015_02192064* var1 = arg0->unknown_2c_;
        struct Struct_ov015_02192064* var2 = 0;
        while (var1 != 0) {
            if ((int)var1->unknown_0_ == var0) {
                break;
            }
            var2 = var1;
            var1 = var1->unknown_4_;
        }

        if (node != 0) {
            struct ListNode02192064* next = node->next;
            func_ov015_0218f0c4(node->value);
            AllocatorUnion_Free(&g_mainAllocator, node->value);
            AllocatorUnion_Free(&g_mainAllocator, node);
            if (prev != 0) {
                prev->next = next;
            } else {
                arg0->unknown_2c_ = var3;
            }
            if (arg0->unknown_34_ == (int)arg0->unknown_30_) {
                arg0->unknown_38_ = *((unsigned char*)arg0->unknown_30_ + 0x1c);
                arg0->unknown_30_ = 0;
            }
            arg0->unknown_34_ = 0;
        }

        arg0->unknown_2b0_ = 0;
        arg0->unknown_1a4_ = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)arg0);
        func_ov015_02192700(arg0, 0);
        break;
    }
    }
}
