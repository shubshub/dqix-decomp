#include <globaldefs.h>

extern "C" void CachedTextTable_Clear(char* table);

// Main, originally ResetBattleObject0203c4c4 (USA 0x0203c4c4, EUR 0x0203c4d4, JPN 0x0203c628)
extern "C" ARM void CachedTextTable_Reset(char* table) {
    CachedTextTable_Clear(table);
}
