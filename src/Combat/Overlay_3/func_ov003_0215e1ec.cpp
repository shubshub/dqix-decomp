#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0215e1ec_963 = 0x3db };
#else
enum { Enum_ov003_0215e1ec_963 = 0x3c3 };
#endif

extern "C" void __clear(void* buf, int len);
unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);

struct Struct_ov003_0215e1ec {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};

struct Struct_ov003_0215e1ec_2 {
    char unknown_0_[Enum_ov003_0215e1ec_963];
    unsigned char unknown_3c3_;
    unsigned char unknown_3c4_[4];
};

// USA: func_ov003_0215e1ec
extern "C" ARM void func_ov003_0215e1ec(struct BattleSide0215e1ec* side) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    __clear(ids, 4);
    int n = GameState_GetOwnPartyOrder((char*)gs, ids);
    side->aliveCount = 0;
    for (int i = 0; i < n; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, ids[i]);
        if (c != NULL) {
            struct CombatantStatus0215e1ec* status = *(struct CombatantStatus0215e1ec**)((char*)c + 0x130);
            int hp = status->hp;
            if (hp > 0) {
                side->aliveIds[side->aliveCount++] = ids[i];
            }
        }
    }
}
