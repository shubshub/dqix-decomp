#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

void* GameState_GetParty(GameState* battleStruct);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c);

struct Obj020a8c4c {
    char pad0[4];
    unsigned char f4;
    char pad5[7];
    int fc;
};

// USA: func_020a8c4c  (semantic: SetOrClearAxisFlagAndNotify_020a8c4c)
extern "C" ARM void func_020a8c4c(struct Obj020a8c4c* obj, unsigned char axis) {
    if ((obj->f4 & (1 << axis)) != 0) {
        return;
    }
    GameState* battle = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    GameObject* c397c = battle->GetLeader();
    GameObject* c800 = battle->GetPartyMemberByIndex(axis);
    GameState_GetParty(battle);
    if (IsScreenNotFullyFaded(ov, false) == 0) {
        GameObject_DisableControl((struct Obj020397cc*)c800, 1);
        *(short*)((char*)c800 + 0xac) = 0;
        if (axis == c397c->obj3D_.actorIndex_) {
            return;
        }
        EnqueueEventTag36_021d2c34(axis, 0, 0);
        return;
    }
    obj->f4 |= (1 << axis);
    *(short*)((char*)c800 + 0xac) = -obj->fc;
    *(unsigned char*)((char*)c800 + 0xc1) |= 8;
}
