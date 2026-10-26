#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0209d8a8_1816 = 0x508 };
#else
enum { Enum_0209d8a8_1816 = 0x718 };
#endif

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" void* func_0209dccc();
extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov017_021b8468(int a);
extern "C" void* func_ov000_02160f08(void* obj);
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);

struct ItemTable;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

struct Struct_0207ccf0_4;
extern "C" int func_0207d200(struct Struct_0207ccf0_4* self, short key, int amount);

struct Struct_0209d8a8 {
    char pad[0x2c];
    struct ItemTable* container;
    void* unknown_30_;
    char pad2[4];
};

struct Struct_0209d8a8_2 {
    char pad[0x90];
    int f90;
    int unknown_94_;
};

// USA: func_0209d8a8
extern "C" ARM int func_0209d8a8(void* obj) {
    Struct_0209d8a8 self;
    int b0;
    int b1;
    GameState_GetParty(GameState::GetInstance());
    Struct_0209d8a8_2* mgr = (Struct_0209d8a8_2*)func_0209dccc();
    if (mgr == NULL) {
        return 0;
    }
    b0 = func_ov017_021d60f4(obj);
    b1 = func_ov017_021d60f4((char*)obj + 8);
    void* base = GetGameResources();
    int field = *(int*)((char*)base + 0x3000 + Enum_0209d8a8_1816);
    void* p = func_ov017_021b8468(field);
    if (p == NULL) {
        return 1;
    }
    void* off = func_ov000_02160f08(p);
    if (off == NULL) {
        return 1;
    }
    struct ItemTable* container = (struct ItemTable*)((char*)off + 0xd0);
    ((SafeAllocator*)&self)->ResetAllocatorPointer();
    ItemTable_Construct(self.pad + 0x14);
    func_0207cbe8(self.pad);
    if (ItemTable_Find(container, (short)b0) != NULL) {
        self.container = container;
        func_0207d200((struct Struct_0207ccf0_4*)&self, b0, (char)b1);
    }
    mgr->f90 = b0;
    mgr->unknown_94_ = b1;
    return 1;
}
