#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);

// USA: func_ov024_021d8d38
extern "C" ARM int func_ov024_021d8d38(int a, int b, int id, int c, int d, int arg5) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetCombatantByIndex(id);
    if (combatant == NULL) {
        return arg5;
    }
    if (func_020885b4((struct Struct_020885b4*)combatant->currentStats_) ||
        func_02088514((struct Struct_02088514*)combatant->currentStats_) ||
        (*(int*)((char*)combatant->currentStats_ + 0x14) & 0x8) != 0) {
        return (int)(arg5 * 1.5f);
    }
    return arg5;
}
