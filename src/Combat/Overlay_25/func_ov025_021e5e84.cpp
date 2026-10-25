#include <globaldefs.h>

#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct Obj02046574;
struct Obj02046574* MessageSystem_GetInstance(void);
void* GetActiveCombatWork_ov000_02160130(void);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);

struct Struct_ov025_021e5e84 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
};

// USA: func_ov025_021e5e84
extern "C" ARM int func_ov025_021e5e84(struct Struct_ov025_021e5e84* arg0, int arg1, int arg2, void* arg3) {
    int var0[8];
    if (func_ov000_021820bc(arg3, arg1, arg0->unknown_9_, (int)&var0[0]) != 1) {
        return 1;
    }

    GameState* bs = GameState::GetInstance();
    struct Obj02046574* names = MessageSystem_GetInstance();
    int id = ids[0];
    GetActiveCombatWork_ov000_02160130();
#if defined(jpn)
    GameObject* c = bs->GetCombatantByIndex(id);
    if (c != NULL) {
        MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c->baseStats_);
    }
#else
    var1->GetCombatantByIndex(var3);

    int isPartyMember = (id >= 0 && id <= 3) ? 1 : 0;
    if (isPartyMember) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, id);
        if (c != NULL) {
            MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c->baseStats_);
        }
    } else {
        GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, id);
        if (c != NULL) {
            MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c + 0x14c);
        }
    }
#endif
    return 1;
}
