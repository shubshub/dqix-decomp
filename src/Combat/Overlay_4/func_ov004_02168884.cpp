#include <globaldefs.h>
#include "GameState/GameState.h"



extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_02011af0(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

// USA: func_ov004_02168884
extern "C" ARM int func_ov004_02168884(void) {
    GameState* battle = GameState::GetInstance();
    func_02011b50(battle, 1);
    func_02011af0(battle);
    void* p = Scenario_GetInstance();
    Scenario_SetFlag(p, (unsigned char*)p + 0x8c, 3, 0);
    return 0;
}
