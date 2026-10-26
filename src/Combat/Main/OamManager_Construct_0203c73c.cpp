#include <globaldefs.h>
extern "C" void CachedTextTable_Construct(char* table);

extern "C" void OamManager_Init(char* oamManager);

enum { kTextTable = 0x10 };  // data_02105ab4's CachedTextTable

// Main, originally InitCombatObject0203c73c (USA 0x0203c73c, EUR 0x0203c74c, JPN 0x0203cc74)
extern "C" ARM char* OamManager_Construct(char* oamManager) {
    CachedTextTable_Construct((char*)(oamManager + kTextTable));
    OamManager_Init((char*)oamManager);
    return oamManager;
}
