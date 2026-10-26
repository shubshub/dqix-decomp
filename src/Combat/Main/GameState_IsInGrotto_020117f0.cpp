#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "World/Zone3D.h"

extern "C" int ZoneId_IsGrotto(int);

extern "C" Zone3D* Zone3D_GetInstance(void);

// Main, originally IsGlobalU16InRange_020117f0 (USA 0x020117f0, EUR 0x02011800, JPN 0x02011560)
extern "C" ARM int GameState_IsInGrotto(GameState* gameState) {
    return ZoneId_IsGrotto((int)Zone3D_GetInstance()->currentZoneID_);
}
