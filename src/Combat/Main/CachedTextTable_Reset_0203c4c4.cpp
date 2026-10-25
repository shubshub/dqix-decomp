#include <globaldefs.h>

void ResetBattleState0203c304(char* obj);

// Main, originally ResetBattleObject0203c4c4 (USA 0x0203c4c4, EUR 0x0203c4d4, JPN 0x0203c628)
ARM void CachedTextTable_Reset(char* obj) {
    ResetBattleState0203c304(obj);
}
