#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" float func_ov017_021d6110(void* obj);

struct S1f8 { char pad[0x1f8]; unsigned char active; char pad2[7]; float unknown_200_; unsigned int unknown_204_; };

// USA: func_ov001_02161e00
extern "C" ARM int func_ov001_02161e00(void* obj) {
    GameState* battle = GameState::GetInstance();
    struct S1f8* combatant = (struct S1f8*)battle->GetCamera();
    int flag = func_ov017_021d60f4(obj);
    float a = func_ov017_021d6110((char*)obj + 8);
    float b = func_ov017_021d6110((char*)obj + 0x10);
    int var5 = (int)(4096.0f * b);
    if (combatant == NULL) {
        return 0;
    }
    if (flag == 0) {
        combatant->active = 0;
    } else {
        combatant->active = 1;
        combatant->unknown_200_ = 1.0f;
        combatant->unknown_204_ = 0x1000;
        combatant->unknown_200_ = a;
        combatant->unknown_204_ = var5;
    }
    return 1;
}
