#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct Obj02061bd8;
struct Slots02083960;

struct Obj0207d200 {
    char pad[0x2c];
    struct ItemTable* container;
};

struct Struct_0201099c_9 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 21;
    unsigned int unknown_b_1_ : 1;
};

extern struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
extern void* GameState_GetParty(GameState* battleStruct);
extern GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
extern int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern unsigned char* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern int CountPositiveSlots02083960(struct Slots02083960* slots);
extern "C" int func_0207ccf0(struct Obj0207d200* self, int key, int one, int id, int zero0, int zero1, int zero2);
extern "C" int func_0207cf30(struct Obj0207d200* self, int key, int count, int zero);
extern "C" void func_0207d134(struct Obj0207d200* self, int key, int count);
extern int UpdateKeyValue0207d200(struct Obj0207d200* self, short key, int amount);
extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

static inline int inline_0207d300(struct Struct_0201099c_9* arg0) {
    return arg0->unknown_8_0_ <= 7;
}

// USA: func_0207d300
extern "C" ARM int func_0207d300(struct Struct_0207ccf0_4* arg0, short arg1, short arg2, int arg3) {
    int var0 = 0;
    if (arg0->unknown_2c_ == NULL) {
        func_0207d6dc((SafeAllocator*)arg0, (int)&arg1, 1);
        var0 = 1;
    }
    int result = -1;
    struct Element020de650* elem = ItemTable_Find(self->container, key);
    if (elem == NULL) {
        result = -2;
    } else if (IsLow(elem) != 0) {
        func_0207d134(self, key, count);
        result = 3;
    } else if (elem->type == 9) {
        UpdateKeyValue0207d200(self, key, count);
        result = 5;
    } else if (elem->flag25) {
        if (func_0207cf30(self, key, count, 0) != 0) {
            result = 2;
        }
    } else {
        GameState* bs = GameState::GetInstance();
        char* p = (char*)GameState_GetParty(bs);
        unsigned char i;
        for (i = 0; i < *(unsigned char*)(p + 0xf7c); i++) {
            int id = *(signed char*)(p + i + 0xf78);
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, id);
            if (c == NULL) {
                continue;
            }
            if (func_02061bd8((struct Struct_0205faf4_11*)var7) != 0) {
                continue;
            }
            if (arg3 != 0) {
                if ((int)*(unsigned short*)(*(char**)((char*)var7 + 0x130) + 4) <= 0) {
                    continue;
                }
                char* var8 = *(char**)((char*)var7 + 0x138);
                if (var8 != NULL && *(unsigned short*)var8 == 0) {
                    continue;
                }
            }
            unsigned char* var9 = func_02053c6c((unsigned char*)var7);
            if (var9 == NULL) {
                continue;
            }
            while (arg2 != 0) {
                if (func_02083960((struct Struct_0207d300*)var9) == 8) {
                    break;
                }
                var1 = func_0207ccf0(arg0, arg1, 1, var6, 0, 0, 0);
                if (var1 != 0) {
                    break;
                }
                arg2 = (short)(arg2 - 1);
            }
        }
        if (arg2 > 0) {
            if (func_0207cf30(arg0, arg1, arg2, 0) != 0) {
                var1 = 2;
            }
        }
    }
    if (initDone) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, sig);
        self->container = NULL;
    }
    return var1;
}
