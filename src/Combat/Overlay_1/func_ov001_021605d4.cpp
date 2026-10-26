#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021605d4
extern "C" ARM int func_ov001_021605d4(void* self) {
    int var0 = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    GameState* battle = GameState::GetInstance();
    int base = var0 * 0xc;
    GameObject* c1 = battle->GetGameObjectByIndex(base + 0x1c);
    if (c1 != NULL && c1->obj3D_.unknown_2_ >= 0) {
        if (flag != 0) {
            c1->obj3D_.MakeVisible();
        } else {
            c1->obj3D_.MakeHidden();
        }
    }
    GameObject* c2 = battle->GetGameObjectByIndex(base + 0x1d);
    if (c2 != NULL && c2->obj3D_.unknown_2_ >= 0) {
        if (flag != 0) {
            c2->obj3D_.MakeVisible();
        } else {
            c2->obj3D_.MakeHidden();
        }
    }
    return 1;
}
