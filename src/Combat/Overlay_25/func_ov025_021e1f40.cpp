#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02049ee8(unsigned char*);
extern "C" int func_02048bd0(unsigned char*);
extern "C" int func_020493a4(unsigned char*);
extern "C" int func_02048c68(unsigned char*);

// USA: func_ov025_021e1f40
extern "C" ARM int func_ov025_021e1f40(GameObject* obj, int targetId) {
#if defined(jpn)
 enum {regionalOffset0=0x180};
#else
 enum {regionalOffset0=0x18c};
#endif
    if (func_02049ee8((unsigned char*)obj) == 0) {
        return 0;
    }
    if (targetId == obj->obj3D_.actorIndex_) {
        return 0;
    }
    if (func_02048bd0((unsigned char*)obj)) {
        return 0;
    }
    if (func_020493a4((unsigned char*)obj) == 0xff) {
        return 0;
    }
    if (func_02048c68((unsigned char*)obj)) {
        return 0;
    }
    int party = 0;
    if (obj->obj3D_.actorIndex_ >= 0 && obj->obj3D_.actorIndex_ <= 3) {
        party = 1;
    }
    if (party) {
        GameState* gs = GameState::GetInstance();
        GameObject* c = func_0200ff1c(gs, obj->obj3D_.actorIndex_);
        if (c != NULL && (*(unsigned int*)((char*)c + regionalOffset0) & 1)) {
            return 0;
        }
    }
    return 1;
}
