#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct KeyMap020a0b3c;
struct KeyMap020a095c;
struct Struct_0205faf4_11;
struct Struct_0207cf30;

extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* func_0207d6dc(SafeAllocator* self, int param1, int param2);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" int func_020a095c(struct KeyMap020a095c* map, int key, int amount);
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" struct Struct_0207cf30* func_02053c6c(unsigned char* obj);
extern "C" GameObject* func_0200ff1c(GameState* gs, int id);

extern "C" void func_0207cc18(void* self, struct Element020de650* elem);

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator __attribute__((aligned(4)));

struct Struct_0207cf30 {
    char pad[0x454];
    short slot[8];
};

struct Struct_0207cf30_2 {
    char pad[0x2c];
    struct ItemTable* container;
    void* unknown_30_;
    void* field34;
};

// USA: func_0207cf30
extern "C" ARM int func_0207cf30(struct Struct_0207cf30_2* self, short key, int max, int enable) {
    int flag = 0;
    if (self->container == NULL) {
        func_0207d6dc((SafeAllocator*)self, (int)&key, 1);
        flag = 1;
    }
    int ret = 0;
    struct Element020de650* elem = ItemTable_Find(self->container, key);
    if (elem != NULL) {
        GameState* gs = GameState::GetInstance();
        char* p = (char*)GameState_GetParty(gs);
        int n = max;
        short i = 0;
        if (enable) {
            int v = func_020a0b3c((struct KeyMap020a0b3c*)GameState_GetParty(gs), key);
            v = 99 - v;
            if (v > max)
                v = max;
            n = (short)v;
        }
        ret = func_020a095c((struct KeyMap020a095c*)p, key, (signed char)n);
        i += n;
        if (ret) {
            func_0207cc18(self, elem);
            self->unknown_30_ = *(void**)((char*)elem + 4);
            self->field34 = gs->GetProtagonist()->baseStats_;
        }
        if (i < max && enable) {
            char* q = (char*)GameState_GetParty(gs);
            for (int j = 0; j < *(unsigned char*)(q + 0xf7c); j++) {
                GameObject* c = func_0200ff1c(gs, *(unsigned char*)(q + j + 0xf78));
                if (c == NULL)
                    continue;
                if (func_02061bd8((struct Struct_0205faf4_11*)c) != 0)
                    continue;
                struct Struct_0207cf30* f = func_02053c6c((unsigned char*)c);
                if (f == NULL)
                    continue;
                for (int k = 0; k < 8; k++) {
                    if (f->slot[k] > 0)
                        continue;
                    f->slot[k] = key;
                    func_0207cc18(self, elem);
                    i++;
                    if (i == max)
                        break;
                }
                if (i == max)
                    break;
            }
        }
    }
    if (flag) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, sig);
        self->container = NULL;
    }
    return ret;
}
