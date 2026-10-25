#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021bf490(void*);
int MessageSystem_GetInstance();
void GameResources_UpdateSpecialItemEffect(void* obj);

typedef int (*StateHandler_021bf534)(void*);
struct StateTable_021bf534 { StateHandler_021bf534 f[9]; };
extern StateTable_021bf534 data_ov017_021d6cc4;

struct Obj_021bf534 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2[8];
    unsigned char state;
};

// Overlay 17, originally func_ov017_021bf534 (USA/EUR 0x021bf534, JPN 0x021bfae0)
extern "C" ARM void FieldTask_OpenCupboard(struct Obj_021bf534* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x228};
#else
 enum {regionalOffset0=0x2d8};
#endif
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetUnknownGameObject();
    GameResources* ov = GetGameResources();
    if (ov) {
        GameResources_UpdateSpecialItemEffect(ov);
    }

    StateTable_021bf534 table = data_ov017_021d6cc4;
    StateHandler_021bf534 handler = table.f[obj->state];
    if (handler) {
        obj->state = (unsigned char)handler(obj);
    } else {
        if (combatant) {
            GameObject_EnableControl(combatant);
        }
        func_ov017_021bf490(obj);
        obj->field1 = 1;
        *(int*)((char*)MessageSystem_GetInstance() + regionalOffset0) = 0;
    }
}
