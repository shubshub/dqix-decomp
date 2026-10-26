#include <globaldefs.h>

enum { kTextTable = 0x10 };  // data_02105ab4's CachedTextTable

extern "C" void CachedTextTable_Clear(char* table);

// Main, originally InitSubObject0203bd78 (USA 0x0203bd78, EUR 0x0203bd88, JPN 0x0203b7d0)
extern "C" ARM void OamManager_ResetTextTable(char* oamManager) {
    CachedTextTable_Clear(oamManager + kTextTable);
}
