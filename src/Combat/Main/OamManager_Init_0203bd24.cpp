#include <globaldefs.h>
#if defined(jpn)
enum { kUnknown0Initial = 0x3000 };
#else
enum { kUnknown0Initial = 0x1000 };
#endif

// data_02105ab4's layout: +0..+8 words of unknown use, +0xc/+0xd the main/sub OAM upload flags
// (OamManager_UploadBuffers), +0x10 the CachedTextTable
enum {
    kUnknown0 = 0x0,
    kUnknown4 = 0x4,
    kUnknown8 = 0x8,
    kUploadMainOam = 0xc,
    kUploadSubOam = 0xd,
    kTextTable = 0x10
};

extern char data_021056b4;   // the sub screen's OAM buffer
extern void* data_02105244;  // the CachedTextTable (CachedTextTable_GetInstance)
extern "C" void CachedTextTable_Clear(char* table);

// Main, originally InitBattleContext0203bd24 (USA 0x0203bd24, EUR 0x0203bd34, JPN 0x0203b77c)
extern "C" ARM void OamManager_Init(char* oamManager) {
    *(int*)(oamManager + kUnknown8) = 0;
    *(unsigned char*)(oamManager + kUploadMainOam) = 1;
    *(unsigned char*)(oamManager + kUploadSubOam) = 1;
    *(int*)(oamManager + kUnknown0) = kUnknown0Initial;
    *(int*)(oamManager + kUnknown4) = 0xe0;
    CachedTextTable_Clear(oamManager + kTextTable);
    *(void**)(oamManager + kTextTable) = &data_021056b4;  // the text table's drawing buffer
    data_02105244 = oamManager + kTextTable;
}
