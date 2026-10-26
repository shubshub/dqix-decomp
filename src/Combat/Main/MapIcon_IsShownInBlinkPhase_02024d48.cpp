#include <globaldefs.h>
struct CombatActionPosition;

// A map icon's flags (CombatActionPosition flag11 and flag12, set by MapDisplay_CollectIcons)
struct Actor02024d48 {
    unsigned char pad[0x11];
    unsigned char inBattle;        // the member's battle id (+0x1b2) is set, and global flag 0x80000 is clear
    unsigned char inProtagonistZone;    // the member is in the protagonist's zone
};

// An icon of a member in a battle in the protagonist's zone is hidden in blink phase 1 (when MapDisplay_DrawBattleMarkers draws
// the battle marker in its place)
// Main, originally CheckActionAllowed (USA 0x02024d48, EUR 0x02024d58, JPN 0x0202471c)
ARM int MapIcon_IsShownInBlinkPhase(CombatActionPosition* icon, int blinkPhase) {
    struct Actor02024d48* flags = (struct Actor02024d48*)icon;
    int result = 1;
    int steady = 1;
    unsigned char inProtagonistZone = flags->inProtagonistZone;
    if (inProtagonistZone != 0) {
        if (inProtagonistZone == 0 || flags->inBattle != 0) {
            steady = 0;
        }
    }
    if (steady == 0) {
        if (inProtagonistZone == 0 || blinkPhase != 0) {
            result = 0;
        }
    }
    return result;
}
