#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0215e1ec_963 = 0x3db };
#else
enum { Enum_ov003_0215e1ec_963 = 0x3c3 };
#endif

extern "C" void __clear(void* buf, int len);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);

struct Struct_ov003_0215e1ec {
    unsigned int flags;
    unsigned short hp;
};

struct Struct_ov003_0215e1ec_2 {
    char pad0[Enum_ov003_0215e1ec_963];
    unsigned char unknown_3c3_;
    unsigned char unknown_3c4_[4];
};

// USA: func_ov003_0215e1ec
extern "C" ARM void func_ov003_0215e1ec(struct Struct_ov003_0215e1ec_2* arg0) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    __clear(ids, 4);
    int n = GameState_GetOwnPartyOrder((char*)gs, ids);
    arg0->unknown_3c3_ = 0;
    for (int i = 0; i < n; i++) {
        GameObject* c = func_0200ff1c(gs, ids[i]);
        if (c != NULL) {
            struct Struct_ov003_0215e1ec* status = *(struct Struct_ov003_0215e1ec**)((char*)c + 0x130);
            int hp = status->hp;
            if (hp > 0) {
                arg0->unknown_3c4_[arg0->unknown_3c3_++] = ids[i];
            }
        }
    }
}
