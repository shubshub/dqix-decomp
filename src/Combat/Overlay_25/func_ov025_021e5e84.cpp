#include <globaldefs.h>

#include "GameState/GameState.h"

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
struct Obj02046574;
extern "C" struct Obj02046574* MessageSystem_GetInstance(void);
extern "C" void* func_ov000_02160130(void);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);

struct Struct_ov025_021e5e84 {
    char pad0[8];
    unsigned char nameIndex;
    unsigned char targetIndex;
};

// USA: func_ov025_021e5e84
extern "C" ARM int func_ov025_021e5e84(struct Struct_ov025_021e5e84* p, int b, int unused, void* obj) {
    int ids[8];
    if (func_ov000_021820bc(obj, b, p->targetIndex, (int)&ids[0]) != 1) {
        return 1;
    }

    GameState* bs = GameState::GetInstance();
    struct Obj02046574* names = MessageSystem_GetInstance();
    int id = ids[0];
    func_ov000_02160130();
#if defined(jpn)
    GameObject* c = bs->GetCombatantByIndex(id);
    if (c != NULL) {
        MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c->baseStats_);
    }
#else
    bs->GetCombatantByIndex(id);

    int isPartyMember = (id >= 0 && id <= 3) ? 1 : 0;
    if (isPartyMember) {
        GameObject* c = func_0200ff1c(bs, id);
        if (c != NULL) {
            MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c->baseStats_);
        }
    } else {
        GameObject* c = func_0200fea4(bs, id);
        if (c != NULL) {
            MessageSystem_SetStringArgument(names, p->nameIndex, (char*)c + 0x14c);
        }
    }
#endif
    return 1;
}
