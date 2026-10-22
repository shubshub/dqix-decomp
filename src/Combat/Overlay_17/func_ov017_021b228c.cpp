#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);

struct Struct_ov017_021b228c;
typedef int (Struct_ov017_021b228c::*Type_02000c9c_3)();

extern const Handler021b228c __ptmf_null;
extern Handler021b228c data_ov017_021d79e0[];

extern int data_ov017_021d83f0;

// USA: func_ov017_021b228c
extern "C" ARM void func_ov017_021b228c(unsigned char* arg0) {
    GameObject* var0 = GameState::GetInstance()->GetUnknownGameObject();
    if (var0 != NULL) {
        func_020397cc((struct Struct_02018300_3*)var0, 1);
    }
    if (!(data_ov017_021d83f0 & 1)) {
        data_ov017_021d79e0[8] = __ptmf_null;
        data_ov017_021d83f0 |= 1;
    }
    int var1 = *(int*)(arg0 + 8);
    if (data_ov017_021d79e0[var1] == 0) return;
    *(int*)(arg0 + 8) = (((Struct_ov017_021b228c*)arg0)->*data_ov017_021d79e0[var1])();
}
