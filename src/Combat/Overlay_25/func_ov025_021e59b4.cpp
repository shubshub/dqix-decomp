#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
struct Struct020372b8;

struct Struct_ov025_021e59b4 {
    char pad[8];
    unsigned char f8;
    unsigned char unknown_9_;
    unsigned short fa;
};

// USA: func_ov025_021e59b4
extern "C" ARM int func_ov025_021e59b4(struct Struct_ov025_021e59b4* obj, int unused, int arg2, void* ctx) {
    GameState* bs = GameState::GetInstance();
    int buf[8];
    int count = func_ov000_021820bc(ctx, unused, obj->f8, (int)buf);
    for (int j = 0; j < count; j++) {
        GameObject* combatant = bs->GetGameObjectByIndex(buf[j]);
        if (combatant) {
            ((Object3D*)((struct Struct020372b8*)combatant))->TransitionInheritedAlpha(obj->unknown_9_, obj->fa);
        }
    }
    return 1;
}
