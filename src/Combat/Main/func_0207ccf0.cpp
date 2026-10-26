#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct Struct_0205faf4_11;
struct Struct_0207ccf0_4;

extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* func_0207d6dc(SafeAllocator* self, int param1, int param2);
extern "C" GameObject* func_0200ff1c(GameState* gs, int flags);
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" unsigned char* func_02053c6c(unsigned char* combatant);
extern "C" int func_0207cf30(void* self, short key, int amount, unsigned char flag);
extern "C" void func_0207cc18(void* self, struct Element020de650* elem);
extern "C" int func_0207d134(void* self, short key, int amount);
extern "C" int func_0207d200(struct Struct_0207ccf0_4* self, short key, int amount);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct Struct_0207ccf0 {
    char pad[0x2c];
    struct ItemTable* container;
    void* unknown_30_;
    int field34;
};

struct Entry0207ccf0 {
    char pad[4];
    void* field4;
    unsigned int type : 4, unused4 : 21, unknown_b_1_ : 1, rest : 6;
};

struct Struct_0207ccf0_3 {
    char pad[0x134];
    int unknown_134_;
};

static inline int inline_0207ccf0(unsigned int type) { return type <= 7; }

// USA: func_0207ccf0
extern "C" ARM int func_0207ccf0(struct Struct_0207ccf0* self, short key, int amount, int flags, unsigned char a, unsigned char b, unsigned char c) {
    int var0 = 0;
    if (self->container == NULL) {
        func_0207d6dc((SafeAllocator*)self, (int)&key, 1);
        var0 = 1;
    }
    int ret = -1;
    struct Entry0207ccf0* elem = (struct Entry0207ccf0*)ItemTable_Find(self->container, key);
    if (elem != NULL) {
        struct Struct_0207ccf0_3* combatant = (struct Struct_0207ccf0_3*)func_0200ff1c(GameState::GetInstance(), flags);
        if (combatant == NULL) return -1;
        if (func_02061bd8((struct Struct_0205faf4_11*)combatant)) return -1;
        short* slots = (short*)(func_02053c6c((unsigned char*)combatant) + 0x454);
        int count = 0;
        if (a && c && elem->unknown_b_1_) {
            if (func_0207cf30(self, key, amount, b)) {
                count = amount;
                ret = 1;
            }
        } else if (elem->type == 8) {
            for (int i = 0; i < 8; i++) {
                if (slots[i] <= 0) {
                    slots[i] = key;
                    count = (short)(count + 1);
                    ret = 0;
                    func_0207cc18(self, (struct Element020de650*)elem);
                    self->unknown_30_ = elem->field4;
                    self->field34 = combatant->unknown_134_;
                    if (count == amount) break;
                }
            }
        }
        if ((ret == 0 && count < amount) || a) {
            short delta = (short)(amount - count);
            if (inline_0207ccf0(elem->type)) {
                if (func_0207d134(self, key, (signed char)delta)) ret = 1;
            } else if (elem->type == 9) {
                if (func_0207d200((struct Struct_0207ccf0_4*)self, key, (signed char)delta)) ret = 1;
            } else {
                if (func_0207cf30(self, key, delta, b)) ret = 1;
            }
        }
    } else {
        ret = -2;
    }
    if (var0) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, sig);
        self->container = NULL;
    }
    return ret;
}
