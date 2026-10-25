#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov015_0218eef0 {};
struct Struct_ov015_0218f02c : Struct_ov015_0218eef0 {};
struct Struct_ov015_02191c70 { Struct_ov015_0218f02c* unknown_0_; Struct_ov015_02191c70* unknown_4_; };
struct Struct_ov015_02191c70_2 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    Struct_ov015_02191c70_2* unknown_8_;
};
struct Struct_ov015_0218bb14 { int unknown_0_; Struct_ov015_02191c70_2* unknown_4_; };
struct Struct_ov015_0218bb14_2 { void* unknown_0_; Struct_ov015_0218bb14* unknown_4_; void* unknown_8_; int unknown_c_; };
struct Struct_ov015_02191c70_3 {
    char unknown_0_[0x2c];
    Struct_ov015_02191c70* unknown_2c_;
    char unknown_30_[0xc];
    Struct_ov015_0218bb14_2 unknown_3c_;
    char unknown_4c_[0x1a4-0x4c];
    int unknown_1a4_;
};
struct Struct_ov015_02191c70_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
};
struct AllocatorUnion;
extern AllocatorUnion g_mainAllocator;
Entry8_0218bb14* GetEntry8_0218bb14(List8_0218bb14*, int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void InitCombatFieldStruct0218eef0(ResetStruct0218eef0*);
int SetFieldAndModeThenDispatch0218f02c(Self0218f02c*, int, int);
extern "C" void func_ov015_0218f0c4(Self0218f02c*);
extern "C" void func_ov015_0218f308(Self0218f02c*, int);
extern "C" int func_ov015_0218f27c(Self0218f02c*, CommandInfo*);

// USA: func_ov015_02191c70
extern "C" ARM void func_ov015_02191c70(Struct_ov015_02191c70_3* arg0, int arg1) {
    Struct_ov015_0218bb14* var0 = func_ov015_0218bb14(&arg0->unknown_3c_, arg1);
    if (!var0) return;
    if (g_keyManager.TestKeysHeld(0x100)) {
        CombatNode* node = self->head;
        while (node) {
            func_ov015_0218f0c4(node->object);
            AllocatorUnion_Free(&g_mainAllocator, node->object);
            CombatNode* old = node;
            node = node->next;
            AllocatorUnion_Free(&g_mainAllocator, old);
        }
        arg0->unknown_2c_ = 0;
    }
    Struct_ov015_02191c70_2* var3 = var0->unknown_4_;
    int var4;
    Struct_ov015_02191c70* var5;
    Struct_ov015_0218f02c* var6 = 0;
    for (; var3; var3 = var3->unknown_8_) {
        var4 = arg0->unknown_1a4_;
        if (var3->unknown_6_ == 8 || var3->unknown_6_ == 9 || var3->unknown_6_ == 10) {
            switch (var3->unknown_6_) {
            case 8: arg0->unknown_1a4_ = 0x1e; break;
            case 9: arg0->unknown_1a4_ = 0x1f; break;
            case 10: arg0->unknown_1a4_ = 0x20; break;
            }
            if (var6) func_ov015_0218f308(var6, var3->unknown_0_);
            arg0->unknown_1a4_ = var4;
        } else if (var3->unknown_6_ == 11) {
            if (var6) func_ov015_0218f308(var6, var3->unknown_0_);
        } else {
            node = (CombatNode*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 8);
            if (!node) return;
            node->object = 0;
            node->next = 0;
            object = node->object = (Self0218f02c*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x5c);
            if (!object) {
                AllocatorUnion_Free(&g_mainAllocator, node);
                return;
            }
            InitCombatFieldStruct0218eef0(object);
            if (!SetFieldAndModeThenDispatch0218f02c(object, (int)self, command->mode)) {
                AllocatorUnion_Free(&g_mainAllocator, node->object);
                node->object = 0;
                AllocatorUnion_Free(&g_mainAllocator, node);
                return;
            }
            CommandInfo info;
            info.value = 0;
            info.secondValue = 0;
            info.parameter = 0;
            info.fieldA = 0;
            info.fieldB = 0;
            info.value = command->value;
            info.secondValue = command->value;
            info.parameter = command->parameter;
            if (!func_ov015_0218f27c(object, &info)) {
                func_ov015_0218f0c4(node->object);
                AllocatorUnion_Free(&g_mainAllocator, node->object);
                node->object = 0;
                AllocatorUnion_Free(&g_mainAllocator, node);
                return;
            }
            Struct_ov015_02191c70** var8 = &arg0->unknown_2c_;
            while (*var8) var8 = &(*var8)->unknown_4_;
            *var8 = var5;
        }
    }
}
