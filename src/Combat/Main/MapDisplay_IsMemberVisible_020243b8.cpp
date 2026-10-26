#include <globaldefs.h>
#include "GameState/GameState.h"

struct Bits40_37464;

// Whether a map icon's object is visible: no object (the ship's 0xff, or an empty slot) counts as visible
// Main, originally CheckCombatantReadyForAction020243b8 (USA 0x020243b8, EUR 0x020243c8, JPN 0x02023d8c)
ARM int MapDisplay_IsMemberVisible(void* unusedSelf, int objectIndex) {
    if (objectIndex < 0) {
        return 1;
    }
    GameObject* object = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), objectIndex);
    if (object == NULL) {
        return 1;
    }
    if (((Object3D*)((struct Bits40_37464*)object))->GetInheritedAlpha() == 0) {
        return 0;
    }
    if (((Object3D*)((unsigned char*)object))->GetAlphaScaleFactor() == 0) {
        return 0;
    }
    return ((Object3D*)((unsigned char*)object))->IsVisible() != 0;
}
