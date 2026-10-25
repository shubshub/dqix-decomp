#include <globaldefs.h>
#if defined(jpn)
#define COMBATANT_ID_OFFSET 0x1ae8
#else
#define COMBATANT_ID_OFFSET 0x1c20
#endif
#include "GameState/GameState.h"

void* GameState_GetParty(GameState* battleStruct);
int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Struct_ov002_0215707c {
    char unknown_0_[0xc];
    short unknown_c_[1];
};

struct Struct_02000c9c_63 {
    char unknown_0_[0xc00];
    Struct_ov002_0215707c unknown_c00_;
    Struct_ov002_0215707c* inline_ov002_0215707c() { return &unknown_c00_; }
};

struct Struct_ov002_0215707c_2 {
    char unknown_0_[0x204];
    Struct_02000c9c_63 unknown_204_;
    Struct_02000c9c_63* inline_ov002_0215707c_2() { return &unknown_204_; }
};

// USA: func_ov002_0215707c
// KEEP-NAME
extern "C" ARM int GetInventoryItemByID(void* arg0, int arg1, int arg2) {
    if (arg1 < 0) {
        return -1;
    }
    if (arg2 < 0) {
        return -1;
    }
    GameState* battle = GameState::GetInstance();
    if (kind == 5) {
        Inventory* p = (Inventory*)GameState_GetParty(battle);
        return p->GetStorage()->GetTable()->items[idx];
    }
    if (kind == 4) {
        char* p = (char*)GameState_GetParty(battle);
        return *(short*)(p + 0xc + idx * 2);
    }
    signed char var3 = *(signed char*)((char*)arg0 + COMBATANT_ID_OFFSET);
    GameObject* var4 = func_0200ff1c(var0, var3);
    if (var4 == 0) {
        return -1;
    }
    return *(short*)((char*)func_02053c6c((unsigned char*)var4) + 0x454 + arg1 * 2);
}
