#include <globaldefs.h>
#include "GameState/GameState.h"
struct ObjectStatePrefix;

extern "C" void GameObject_FreezeAnimation(ObjectStatePrefix* obj);
extern "C" void GameObject_UnfreezeAnimation(ObjectStatePrefix* obj);
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);

struct Struct_ov025_021e7520 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int unknown_c_;
};

// USA: func_ov025_021e7520
extern "C" ARM int func_ov025_021e7520(struct Struct_ov025_021e7520* p, int unused, int arg2, void* obj) {
    GameState* bs = GameState::GetInstance();
    int ids[8];
    int count = func_ov000_021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetWanderingMonsterByIndex(ids[i]);
        if (c) {
            if (p->unknown_c_ != 0) {
                GameObject_FreezeAnimation((ObjectStatePrefix*)c);
            } else {
                GameObject_UnfreezeAnimation((ObjectStatePrefix*)c);
            }
        }
    }
    return 1;
}
