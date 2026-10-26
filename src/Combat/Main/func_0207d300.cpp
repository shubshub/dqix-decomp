#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct Struct_0205faf4_11;
struct Struct_0207d300;

struct Struct_0207ccf0_4 {
    char pad[0x2c];
    struct ItemTable* container;
};

struct Element020de650 {
    char pad[8];
    unsigned int type : 4;
    unsigned int unk4 : 21;
    unsigned int unknown_b_1_ : 1;
};

extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* func_0207d6dc(SafeAllocator* self, int param1, int param2);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" int func_02083960(struct Struct_0207d300* slots);
extern "C" int func_0207ccf0(struct Struct_0207ccf0_4* self, int key, int one, int id, int arg4, int arg5, int arg6);
extern "C" int func_0207cf30(struct Struct_0207ccf0_4* self, int key, int count, int zero);
extern "C" void func_0207d134(struct Struct_0207ccf0_4* self, int key, int count);
extern "C" int func_0207d200(struct Struct_0207ccf0_4* self, short key, int amount);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

static inline int inline_0207d300(struct Element020de650* e) {
    return e->type <= 7;
}

// USA: func_0207d300
extern "C" ARM int func_0207d300(struct Struct_0207ccf0_4* self, short key, short count, int flag) {
    int var0 = 0;
    if (self->container == NULL) {
        func_0207d6dc((SafeAllocator*)self, (int)&key, 1);
        var0 = 1;
    }
    int result = -1;
    struct Element020de650* elem = ItemTable_Find(self->container, key);
    if (elem == NULL) {
        result = -2;
    } else if (inline_0207d300(elem) != 0) {
        func_0207d134(self, key, count);
        result = 3;
    } else if (elem->type == 9) {
        func_0207d200(self, key, count);
        result = 5;
    } else if (elem->unknown_b_1_) {
        if (func_0207cf30(self, key, count, 0) != 0) {
            result = 2;
        }
    } else {
        GameState* bs = GameState::GetInstance();
        char* p = (char*)GameState_GetParty(bs);
        unsigned char i;
        for (i = 0; i < *(unsigned char*)(p + 0xf7c); i++) {
            int id = *(signed char*)(p + i + 0xf78);
            GameObject* c = func_0200ff1c(bs, id);
            if (c == NULL) {
                continue;
            }
            if (func_02061bd8((struct Struct_0205faf4_11*)c) != 0) {
                continue;
            }
            if (flag != 0) {
                if ((int)*(unsigned short*)(*(char**)((char*)c + 0x130) + 4) <= 0) {
                    continue;
                }
                char* var8 = *(char**)((char*)c + 0x138);
                if (var8 != NULL && *(unsigned short*)var8 == 0) {
                    continue;
                }
            }
            unsigned char* slots = func_02053c6c((unsigned char*)c);
            if (slots == NULL) {
                continue;
            }
            while (count != 0) {
                if (func_02083960((struct Struct_0207d300*)slots) == 8) {
                    break;
                }
                result = func_0207ccf0(self, key, 1, id, 0, 0, 0);
                if (result != 0) {
                    break;
                }
                count = (short)(count - 1);
            }
        }
        if (count > 0) {
            if (func_0207cf30(self, key, count, 0) != 0) {
                result = 2;
            }
        }
    }
    if (var0) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, sig);
        self->container = NULL;
    }
    return result;
}
