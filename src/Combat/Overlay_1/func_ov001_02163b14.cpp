#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov017_021d612c(void* obj);
extern "C" void* func_02010768(void* obj);
extern "C" void* GameState_GetZoneTable(void* obj);
struct List0209998c;
struct Elem0209998c;
extern "C" Elem0209998c* ZoneTable_FindEntryByMapCode(List0209998c* list, const char* name);
extern "C" void Zone3D_Init(char* obj, int a, int b);
extern "C" void _ZN6Zone3D10SwitchZoneEti(void* g, int val, int flag);

struct GlobalBlock_02163b14 {
#if defined(jpn)
    char pad[0x6c];
#else
    char pad[0x4c];
#endif
    SafeAllocator* allocator;
    int unknown_50_;
};

// USA: func_ov001_02163b14
extern "C" ARM int func_ov001_02163b14(void* obj) {
    GameState* battle = GameState::GetInstance();
    struct GlobalBlock_02163b14* g = (struct GlobalBlock_02163b14*)Zone3D_GetInstance();
    void* fieldPtr = func_02010768(battle);
    int type = *(int*)obj;
    int key = -1;
    if (type == 0) {
        key = func_ov017_021d60f4(obj);
    } else if (type == 2) {
        key = (int)func_ov017_021d612c(obj);
        if (key == 0) return 0;
        void* table = GameState_GetZoneTable(battle);
        struct Elem0209998c* entry = ZoneTable_FindEntryByMapCode((struct List0209998c*)table, (const char*)key);
        if (entry == 0) return 0;
        key = *(unsigned short*)entry;
    }
    if (key < 0) return 0;

    SafeAllocator* allocator = g->allocator;
    int extra = g->unknown_50_;

#if defined(jpn)
    void* p1 = allocator->Allocate(0x2864);
#else
    void* p1 = allocator->Allocate(0x2824);
#endif
    if (p1 == 0) return 0;

    SafeAllocator* p2 = (SafeAllocator*)allocator->Allocate(0x14);
    unsigned int maxAlloc = allocator->GetMaxPossibleAllocation();
    void* p3 = allocator->Allocate(maxAlloc);
    p2->CreateTypeA(p3, maxAlloc);

    Zone3D_Init((char*)p1, (int)p2, extra);
    _ZN6Zone3D10SwitchZoneEti(p1, key, 0);

    *(void**)fieldPtr = p1;
    return 1;
}
