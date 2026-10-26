#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);

struct Flags02033fdc;
struct Flags02033fcc;
void GameObject_ResumeMovement(struct Flags02033fdc* p);
void GameObject_PauseMovement(struct Flags02033fcc* p);

struct Param021e7e34 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int field_c;
};

// USA: func_ov025_021e7e34  (semantic: DispatchAndUpdateFlag_021e7e34)
extern "C" ARM int func_ov025_021e7e34(struct Param021e7e34* p, int unused, int unusedR2, void* obj) {
    GameState* bs = GameState::GetInstance();
    int ids[12];
    int count = DispatchByIndex021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetWanderingMonsterByIndex(ids[i]);
        if (c) {
            if (p->field_c != 0) {
                GameObject_ResumeMovement((struct Flags02033fdc*)c);
            } else {
                GameObject_PauseMovement((struct Flags02033fcc*)c);
            }
        }
    }
    return 1;
}
