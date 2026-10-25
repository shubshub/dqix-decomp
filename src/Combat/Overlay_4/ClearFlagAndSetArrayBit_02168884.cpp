#include <globaldefs.h>
#include "GameState/GameState.h"



int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void ClearFieldKeepBit0x10_02011af0(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

// USA: func_ov004_02168884  (semantic: ClearFlagAndSetArrayBit_02168884)
extern "C" ARM int func_ov004_02168884(void) {
    GameState* battle = GameState::GetInstance();
    CheckBitsInField0x63dc_02011b50(battle, 1);
    ClearFieldKeepBit0x10_02011af0(battle);
    void* p = Scenario_GetInstance();
    Scenario_SetFlag(p, (unsigned char*)p + 0x8c, 3, 0);
    return 0;
}
