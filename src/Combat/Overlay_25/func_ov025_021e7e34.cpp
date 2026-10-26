#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);

struct Flags02033fdc;
struct Flags02033fcc;
extern "C" void GameObject_ResumeMovement(struct Flags02033fdc* p);
extern "C" void GameObject_PauseMovement(struct Flags02033fcc* p);

struct Struct_ov025_021e7e34 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int unknown_c_;
};

// USA: func_ov025_021e7e34
extern "C" ARM int func_ov025_021e7e34(struct Struct_ov025_021e7e34* p, int unused, int arg2, void* obj) {
    GameState* bs = GameState::GetInstance();
    int ids[12];
    int count = func_ov000_021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetWanderingMonsterByIndex(ids[i]);
        if (c) {
            if (p->unknown_c_ != 0) {
                GameObject_ResumeMovement((struct Flags02033fdc*)c);
            } else {
                GameObject_PauseMovement((struct Flags02033fcc*)c);
            }
        }
    }
    return 1;
}
