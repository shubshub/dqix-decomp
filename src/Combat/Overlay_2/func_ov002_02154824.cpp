#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0201bc94;
struct Struct_020541a4;

extern "C" void func_ov002_02153e90(void* obj);
extern "C" struct Struct0201bc94* Zone3D_GetInstance();
extern "C" int func_0201bc94(struct Struct0201bc94* obj);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" void func_020541a4(struct Struct_020541a4* obj, unsigned char val);

// USA: func_ov002_02154824
extern "C" ARM int func_ov002_02154824(void* unused, unsigned char* obj, int flag) {
    GameState* battleStruct;
    unsigned char* base;
    int i;
    int result;

    if (obj == NULL) return 0;
    if (flag == 0) return 0;

    result = 0;
    func_ov002_02153e90(obj + 8);
    if (func_0201bc94(Zone3D_GetInstance())) {
        battleStruct = GameState::GetInstance();
        base = (unsigned char*)GameState_GetParty(battleStruct);
        for (i = 0; i < (int)base[0xf7c]; i++) {
            unsigned char* p = base + i;
            GameObject* combatant = battleStruct->GetPartyMemberByIndex(p[0xf78]);
            func_020541a4((struct Struct_020541a4*)combatant, 1);
        }

        obj[0x8] = 3;
        result = 1;
        *(int*)(obj + 0x38) = result;
    }

    return result;
}
