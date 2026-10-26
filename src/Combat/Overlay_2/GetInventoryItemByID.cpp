#include <globaldefs.h>
#if defined(jpn)
#define COMBATANT_ID_OFFSET 0x1ae8
#else
#define COMBATANT_ID_OFFSET 0x1c20
#endif
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_02053c6c(unsigned char* obj);

struct ItemTable {
    char unk0[0xc];
    short items[1];
};

struct Struct_02000c9c_63 {
    char unk0[0xc00];
    ItemTable table;
    ItemTable* inline_ov002_0215707c() { return &table; }
};

struct Inventory {
    char unk0[0x204];
    Struct_02000c9c_63 storage;
    Struct_02000c9c_63* inline_ov002_0215707c_2() { return &storage; }
};

// USA: func_ov002_0215707c
// KEEP-NAME
extern "C" ARM int GetInventoryItemByID(void* self, int idx, int kind) {
    if (idx < 0) {
        return -1;
    }
    if (kind < 0) {
        return -1;
    }
    GameState* battle = GameState::GetInstance();
    if (kind == 5) {
        Inventory* p = (Inventory*)GameState_GetParty(battle);
        return p->inline_ov002_0215707c_2()->inline_ov002_0215707c()->items[idx];
    }
    if (kind == 4) {
        char* p = (char*)GameState_GetParty(battle);
        return *(short*)(p + 0xc + idx * 2);
    }
    signed char id = *(signed char*)((char*)self + COMBATANT_ID_OFFSET);
    GameObject* combatant = func_0200ff1c(battle, id);
    if (combatant == 0) {
        return -1;
    }
    return *(short*)((char*)func_02053c6c((unsigned char*)combatant) + 0x454 + idx * 2);
}
