#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02049ee8(unsigned char*);
extern "C" int func_02048bd0(unsigned char*);
extern "C" int func_020493a4(unsigned char*);
extern "C" int func_02048c68(unsigned char*);

// USA: func_ov025_021e1f40
extern "C" ARM int func_ov025_021e1f40(GameObject* arg0, int arg1) {
#if defined(jpn)
 enum {Enum_ov025_021e1f40_396=0x180};
#else
 enum {Enum_ov025_021e1f40_396=0x18c};
#endif
    if (func_02049ee8((unsigned char*)arg0) == 0) {
        return 0;
    }
    if (targetId == obj->obj3D_.actorIndex_) {
        return 0;
    }
    if (func_02048bd0((unsigned char*)arg0)) {
        return 0;
    }
    if (func_020493a4((unsigned char*)arg0) == 0xff) {
        return 0;
    }
    if (func_02048c68((unsigned char*)arg0)) {
        return 0;
    }
    int party = 0;
    if (obj->obj3D_.actorIndex_ >= 0 && obj->obj3D_.actorIndex_ <= 3) {
        party = 1;
    }
    if (party) {
        GameState* gs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, obj->obj3D_.actorIndex_);
        if (c != NULL && (*(unsigned int*)((char*)c + regionalOffset0) & 1)) {
            return 0;
        }
    }
    return 1;
}
