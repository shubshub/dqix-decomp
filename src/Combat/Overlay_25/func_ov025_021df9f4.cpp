#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021df9f4 {
    char unknown_0_[0xc0];
    unsigned char unknown_c0_;
#if defined(jpn)
    char unknown_c1_[0x180 - 0xc1];
#else
    char unknown1_c1_[0x18c - 0xc1];
#endif
    unsigned int unknown_18c_;
};

extern "C" int func_02049ec0(unsigned char*);
extern "C" int func_02048c10(unsigned char*);
extern "C" int func_02048c68(unsigned char*);

// USA: func_ov025_021df9f4
extern "C" ARM int func_ov025_021df9f4(GameObject* arg0) {
    if (arg0 == 0) {
        return 0;
    }
    int var0 = 0;
    if (arg0->obj3D_.IsVisible() && func_02049ec0((unsigned char*)arg0) &&
        !func_02048c10((unsigned char*)arg0)) {
        if (!func_02048c68((unsigned char*)arg0)) {
            var0 = 1;
        }
    }
    bool isParty = false;
    if (obj->obj3D_.actorIndex_ >= 0 && obj->obj3D_.actorIndex_ <= 3) {
        isParty = true;
    }
    if (isParty) {
        GameState* gs = GameState::GetInstance();
        Combatant021df9f4* c = (Combatant021df9f4*)GetCombatantWithFlag0x100_0200ff1c(gs, obj->obj3D_.actorIndex_);
        if (c != 0 && ((c->flags & 1) || c->state == 8)) {
            result = 0;
        }
    }
    return var0;
}
