#include <globaldefs.h>

#if defined(jpn)
enum { kFieldOffset = 0x508 };
#else
enum { kFieldOffset = 0x718 };
#endif

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void* GameState_GetParty(GameState* battleStruct);
void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov017_021b8468(int a);
void* GetOffsetPtr02160f08(void* obj);
void* ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);

struct ItemTable;
struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

struct Obj0207d200;
int UpdateKeyValue0207d200(struct Obj0207d200* self, short key, int amount);

struct SelfBuf0209d8a8 {
    char pad[0x2c];
    struct ItemTable* container;
    void* field30;
    char pad2[4];
};

struct GlobalManagerFields0209d8a8 {
    char pad[0x90];
    int f90;
    int f94;
};

// USA: func_0209d8a8  (semantic: InitAndRegisterEntry_0209d8a8)
extern "C" ARM int func_0209d8a8(void* obj) {
    SelfBuf0209d8a8 self;
    int b0;
    int b1;
    GameState_GetParty(GameState::GetInstance());
    GlobalManagerFields0209d8a8* mgr = (GlobalManagerFields0209d8a8*)GetGlobalManager0209dccc();
    if (mgr == NULL) {
        return 0;
    }
    b0 = func_ov017_021d60f4(obj);
    b1 = func_ov017_021d60f4((char*)obj + 8);
    void* base = GetGameResources();
    int field = *(int*)((char*)base + 0x3000 + kFieldOffset);
    void* p = func_ov017_021b8468(field);
    if (p == NULL) {
        return 1;
    }
    void* off = GetOffsetPtr02160f08(p);
    if (off == NULL) {
        return 1;
    }
    struct ItemTable* container = (struct ItemTable*)((char*)off + 0xd0);
    ((SafeAllocator*)&self)->ResetAllocatorPointer();
    ItemTable_Construct(self.pad + 0x14);
    InitStruct0207cbe8(self.pad);
    if (ItemTable_Find(container, (short)b0) != NULL) {
        self.container = container;
        UpdateKeyValue0207d200((struct Obj0207d200*)&self, b0, (char)b1);
    }
    mgr->f90 = b0;
    mgr->f94 = b1;
    return 1;
}
