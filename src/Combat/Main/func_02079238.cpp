#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02079238_4 { unsigned int flags; };

struct Struct_02079238 {
    Object3D object;
    char     unknownAc[0xae - 0xac];
    short    unknown_ae_;
    char     unknown_b0_[0xc0 - 0xb0];
    unsigned char kind;
    char     unknownC1[0xc3 - 0xc1];
    unsigned char state;
    char     unknown_c4_[0x130 - 0xc4];
    Struct_02079238_4* flags;
};

struct Struct_02079238_2 { char unknown0[0x56c]; unsigned char unknown_56c_; };

struct Struct_02079238_3 { int x, y, z; };

extern "C" int func_02039860(void*);
extern "C" int func_020342ac(GameObject*);
extern "C" Struct_02079238_2* func_02053c6c(unsigned char*);
extern "C" int func_02034340(void*);
extern "C" Struct_02079238_3 func_02034104(GameObject*);
extern "C" void __clear(void* dst, int size);
int fix32sin(int x);
int fix32cos(int x);

// USA: func_02079238
extern "C" ARM short func_02079238(Object3D* arg0, int arg1) {
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        GameObject* candidate = state->GetPartyMemberByIndex(i);
        if (!candidate) {
            if (i == 0) return -1;
            continue;
        }
        if (func_02039860(candidate) != -1) continue;
        if (arg0->GetField06() != candidate->obj3D_.GetField06()) continue;
        Struct_02079238* view = (Struct_02079238*)candidate;
        if (!func_020342ac(candidate)) continue;
        if (view->kind == 6) continue;
        if (candidate->obj3D_.GetField06() != arg0->GetField06()) continue;
        if (func_02053c6c((unsigned char*)candidate)->unknown_56c_ != 0) continue;
        if (view->flags->flags & 1) continue;
        if ((int)view->state > 0) continue;
        if (func_02034340(candidate)) continue;
        Struct_02079238_3 copy = func_02034104(candidate);
        Struct_02079238_3 offset;
        Vector3fix_Subtract((const Vector3fix*)&copy,
                            &arg0->position_,
                            (Vector3fix*)&offset);
        int dist = Vector3fix_Length((const Vector3fix*)&offset);
        if (dist <= arg1) {
            short facing = ((Struct_02079238*)arg0)->unknown_ae_;
            Struct_02079238_3 dir;
            __clear(&dir, 0xc);
            dir.x = fix32sin(facing);
            dir.z = fix32cos(facing);
            if (fix32_Divide(Vector3fix_InnerProduct((const Vector3fix*)&offset,
                                                     (const Vector3fix*)&dir), dist) > 0xb50)
                return (short)i;
        }
    }
    return -1;
}
