#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
extern struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
extern void* GameState_GetParty(GameState* battleStruct);

struct KeyMap020a095c;
extern int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);

extern "C" void func_0207cc18(void* self, struct Element020de650* elem);

extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

struct Obj0207d200 {
    char pad[0x2c];
    struct ItemTable* container;
    void* field30;
};

// USA: func_0207d200
ARM int UpdateKeyValue0207d200(struct Obj0207d200* self, short key, int amount) {
    int flag = 0;
    if (self->container == NULL) {
        InitAllocatorAndLoadGp2File0207d6dc((SafeAllocator*)self, (int)&key, 1);
        flag = 1;
    }
    int ret = 0;
    struct Element020de650* elem = ItemTable_Find(self->container, key);
    if (elem != NULL) {
        GameState* battleStruct = GameState::GetInstance();
        char* p = (char*)GameState_GetParty(battleStruct) + 0xe04;
        ret = AddKeyValueClamped020a095c((struct KeyMap020a095c*)p, key, amount);
        if (ret) {
            func_0207cc18(self, elem);
            self->field30 = *(void**)((char*)elem + 4);
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
