#include <globaldefs.h>

void CachedTextTable_Clear(char* table);

// Main, originally ResetBattleObject0203c4c4 (USA 0x0203c4c4, EUR 0x0203c4d4, JPN 0x0203c628)
ARM void CachedTextTable_Reset(char* table) {
    CachedTextTable_Clear(table);
}
