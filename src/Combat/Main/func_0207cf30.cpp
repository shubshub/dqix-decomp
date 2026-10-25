#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct KeyMap020a0b3c;
struct KeyMap020a095c;
struct Obj02061bd8;
struct Obj0207cf30Field;

extern struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
extern void* GameState_GetParty(GameState* battleStruct);
extern int LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
extern int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);
extern int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern struct Obj0207cf30Field* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);

extern "C" void func_0207cc18(void* arg0, struct Struct_0201099c_9* arg1);

extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator __attribute__((aligned(4)));

struct Struct_0207cf30 {
    char unknown_0_[0x454];
    short unknown_454_[8];
};

struct Obj0207cf30 {
    char pad[0x2c];
    struct ItemTable* container;
    void* field30;
    void* field34;
};

// USA: func_0207cf30
extern "C" ARM int func_0207cf30(struct Struct_0207cf30_2* arg0, short arg1, int arg2, int arg3) {
    int var0 = 0;
    if (arg0->unknown_2c_ == NULL) {
        func_0207d6dc((SafeAllocator*)arg0, (int)&arg1, 1);
        var0 = 1;
    }
    int ret = 0;
    struct Element020de650* elem = ItemTable_Find(self->container, key);
    if (elem != NULL) {
        GameState* gs = GameState::GetInstance();
        char* p = (char*)GameState_GetParty(gs);
        int n = max;
        short i = 0;
        if (enable) {
            int v = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)GameState_GetParty(gs), key);
            v = 99 - v;
            if (v > max)
                v = max;
            n = (short)v;
        }
        var1 = func_020a095c((struct Struct_0207cf30_4*)var4, arg1, (signed char)var5);
        var6 += var5;
        if (var1) {
            func_0207cc18(arg0, var2);
            arg0->unknown_30_ = *(void**)((char*)var2 + 4);
            arg0->unknown_34_ = var3->GetProtagonist()->baseStats_;
        }
        if (i < max && enable) {
            char* q = (char*)GameState_GetParty(gs);
            for (int j = 0; j < *(unsigned char*)(q + 0xf7c); j++) {
                GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, *(unsigned char*)(q + j + 0xf78));
                if (c == NULL)
                    continue;
                if (func_02061bd8((struct Struct_0205faf4_11*)var10) != 0)
                    continue;
                struct Struct_0207cf30* var11 = func_02053c6c((unsigned char*)var10);
                if (var11 == NULL)
                    continue;
                for (int var12 = 0; var12 < 8; var12++) {
                    if (var11->unknown_454_[var12] > 0)
                        continue;
                    var11->unknown_454_[var12] = arg1;
                    func_0207cc18(arg0, var2);
                    var6++;
                    if (var6 == arg2)
                        break;
                }
                if (var6 == arg2)
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
    return var1;
}
