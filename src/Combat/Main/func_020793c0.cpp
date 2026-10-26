#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct_020793c0_4 { unsigned int flags; };
struct Struct_020793c0 {
    Object3D object;
    char unknownAc[0xc0-0xac];
    unsigned char kind;
    char unknownC1[2];
    unsigned char state;
    char unknown_c4_[0x130-0xc4];
    Struct_020793c0_4* flags;
};
struct Struct_020793c0_2 { char unknown0[0x56c]; unsigned char unknown_56c_; };
extern "C" int func_02039860(void*);
extern "C" int func_020342ac(GameObject*);
extern "C" Struct_020793c0_2* func_02053c6c(unsigned char*);
extern "C" int func_02034340(void*);
struct Struct_020793c0_3 { int x, y, z; };
extern "C" Struct_020793c0_3 func_02034104(GameObject*);
extern "C" int Vector3fix_Distance(const Vector3fix*, const Vector3fix*);
// USA: func_020793c0
extern "C" ARM short func_020793c0(Object3D* arg0, int arg1) {
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        GameObject* candidate = state->GetPartyMemberByIndex(i);
        if (!candidate) {
            if (i == 0) return -1;
            continue;
        }
        if (func_02039860(candidate) != -1) continue;
        if (!func_020342ac(candidate)) continue;
        if (arg0->GetField06() != candidate->obj3D_.GetField06()) continue;
        Struct_020793c0* view = (Struct_020793c0*)candidate;
        if (view->kind == 6) continue;
        if (candidate->obj3D_.GetField06() != arg0->GetField06()) continue;
        if (func_02053c6c((unsigned char*)candidate)->unknown_56c_ != 0) continue;
        if (view->flags->flags & 1) continue;
        if ((int)view->state > 0) continue;
        if (func_02034340(candidate)) continue;
        Struct_020793c0_3 copy = func_02034104(candidate);
        if (Vector3fix_Distance((Vector3fix*)&copy, &arg0->position_) < arg1) return (short)i;
    }
    return -1;
}
