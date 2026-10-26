#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

struct Struct_ov017_021b228c;
typedef int (Struct_ov017_021b228c::*Type_02000c9c_3)();

extern const Handler021b228c __ptmf_null;
extern Handler021b228c data_ov017_021d79e0[];

extern int data_ov017_021d83f0;

// Overlay 17, originally func_ov017_021b228c (USA/EUR 0x021b228c, JPN 0x021b29a4)
extern "C" ARM void FieldTask_RunMenuScreen(unsigned char* self) {
    GameObject* combatant = GameState::GetInstance()->GetLeader();
    if (combatant != NULL) {
        GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
    }
    if (!(data_ov017_021d83f0 & 1)) {
        data_ov017_021d79e0[8] = __ptmf_null;
        data_ov017_021d83f0 |= 1;
    }
    int var1 = *(int*)(arg0 + 8);
    if (data_ov017_021d79e0[var1] == 0) return;
    *(int*)(arg0 + 8) = (((Struct_ov017_021b228c*)arg0)->*data_ov017_021d79e0[var1])();
}
