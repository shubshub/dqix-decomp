#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov015_0218eef0 {};
struct Self0218f02c : Struct_ov015_0218eef0 {};
struct CombatNode { Self0218f02c* object; CombatNode* next; };
struct Struct_ov015_02191c70_2 {
    int value;
    unsigned short parameter;
    unsigned char mode;
    unsigned char unknown_7_;
    Struct_ov015_02191c70_2* next;
};
struct Struct_ov015_0218bb14 { int value; Struct_ov015_02191c70_2* commands; };
struct Struct_ov015_0218bb14_2 { void* field0; Struct_ov015_0218bb14* entries; void* field8; int count; };
struct Struct_ov015_02191c70_3 {
    char pad0[0x2c];
    CombatNode* head;
    char unknown_30_[0xc];
    Struct_ov015_0218bb14_2 list;
    char unknown_4c_[0x1a4-0x4c];
    int state;
};
struct Struct_ov015_02191c70_4 {
    int value;
    int unknown_4_;
    unsigned short parameter;
    unsigned char fieldA;
    unsigned char fieldB;
};
struct AllocatorUnion;
extern AllocatorUnion g_mainAllocator;
extern "C" Struct_ov015_0218bb14* func_ov015_0218bb14(Struct_ov015_0218bb14_2*, int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_ov015_0218eef0(Struct_ov015_0218eef0*);
extern "C" int func_ov015_0218f02c(Self0218f02c*, int, int);
extern "C" void func_ov015_0218f0c4(Self0218f02c*);
extern "C" void func_ov015_0218f308(Self0218f02c*, int);
extern "C" int func_ov015_0218f27c(Self0218f02c*, Struct_ov015_02191c70_4*);

// USA: func_ov015_02191c70
extern "C" ARM void func_ov015_02191c70(Struct_ov015_02191c70_3* self, int index) {
    Struct_ov015_0218bb14* entry = func_ov015_0218bb14(&self->list, index);
    if (!entry) return;
    if (g_keyManager.TestKeysHeld(0x100)) {
        CombatNode* node = self->head;
        while (node) {
            func_ov015_0218f0c4(node->object);
            AllocatorUnion_Free(&g_mainAllocator, node->object);
            CombatNode* old = node;
            node = node->next;
            AllocatorUnion_Free(&g_mainAllocator, old);
        }
        self->head = 0;
    }
    Struct_ov015_02191c70_2* command = entry->commands;
    int var4;
    CombatNode* node;
    Self0218f02c* object = 0;
    for (; command; command = command->next) {
        var4 = self->state;
        if (command->mode == 8 || command->mode == 9 || command->mode == 10) {
            switch (command->mode) {
            case 8: self->state = 0x1e; break;
            case 9: self->state = 0x1f; break;
            case 10: self->state = 0x20; break;
            }
            if (object) func_ov015_0218f308(object, command->value);
            self->state = var4;
        } else if (command->mode == 11) {
            if (object) func_ov015_0218f308(object, command->value);
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
            func_ov015_0218eef0(object);
            if (!func_ov015_0218f02c(object, (int)self, command->mode)) {
                AllocatorUnion_Free(&g_mainAllocator, node->object);
                node->object = 0;
                AllocatorUnion_Free(&g_mainAllocator, node);
                return;
            }
            Struct_ov015_02191c70_4 info;
            info.value = 0;
            info.unknown_4_ = 0;
            info.parameter = 0;
            info.fieldA = 0;
            info.fieldB = 0;
            info.value = command->value;
            info.unknown_4_ = command->value;
            info.parameter = command->parameter;
            if (!func_ov015_0218f27c(object, &info)) {
                func_ov015_0218f0c4(node->object);
                AllocatorUnion_Free(&g_mainAllocator, node->object);
                node->object = 0;
                AllocatorUnion_Free(&g_mainAllocator, node);
                return;
            }
            CombatNode** tail = &self->head;
            while (*tail) tail = &(*tail)->next;
            *tail = node;
        }
    }
}
