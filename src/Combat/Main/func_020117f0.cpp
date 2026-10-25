#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"

extern "C" int func_0201b588(int);

extern "C" unsigned short *Zone3D_GetInstance(void);

// USA: func_020117f0
ARM int IsGlobalU16InRange_020117f0(GameState *) {
    return IsInRange0201b588((int) (*Zone3D_GetInstance()));
}
