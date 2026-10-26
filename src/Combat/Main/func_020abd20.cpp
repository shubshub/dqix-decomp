#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"


extern char g_fileLoadBuffer[];

extern "C" void* Zone3D_GetInstance();
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
extern "C" void* Scenario_GetInstance();
extern "C" void func_020a9a50(void* ctx, char* dst, int flag);
void CopyBlobIntoBattleStruct020a9ba4(void* blob);
void LoadBattleRegion0x5cdc_020a9af8(unsigned char* p);
extern "C" void func_020a9b2c(void* p);
void ClearAllTreasureMapUnknownBits_020116c8(void* p);
void* GameState_GetPlayerLocation(char* p, unsigned int index);

struct Struct_02011544;
extern "C" void func_02011544(struct Struct_02011544* arg0);

// USA: func_020abd20
extern "C" ARM int func_020abd20() {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    unsigned char* zone = (unsigned char*)Zone3D_GetInstance();
    gs->unknown_5cc8_ = 0;
    char buf[8];
    if (func_020aaf84(buf, 0, 0, 1) == 0) {
        SetFlag0x5cccBit0_02011544((struct StateBits5ccc_11544*)gs);
        return 0;
    }
    {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        unsigned char* base = (unsigned char*)&g_fileLoadBuffer[0] + 0x28000;
        func_020a9a50(base + 0x2cac, (char*)Scenario_GetInstance(), 1);
        memcpy(((unsigned char*)GameState::GetInstance()) + 0x5e6c, base + 0x6c3c, 0x110);
        CopyBlobIntoBattleStruct020a9ba4(base + 0x5a04);
        LoadBattleRegion0x5cdc_020a9af8(base + 0x33c0);
        func_020a9b2c(base + 0x3ec4);
        unsigned char* sub = base + 4;
        *(unsigned short*)((zone + 0x2700) + 0x86) = *(unsigned short*)(sub + 0x2c5c);
        *(unsigned short*)((zone + 0x2700) + 0x84) = *(short*)(sub + 0x2c5e);
        ((Vector3i*)(zone + 0x2774))->operator=(*((const Vector3i*)(sub + 0x2c60)));
        *(unsigned int*)(zone + 0x2780) = *(unsigned int*)(sub + 0x2c6c);
        *(unsigned char*)(zone + 0x2788) = *(unsigned char*)(sub + 0x2c74);
        *(unsigned int*)(zone + 0x2794) = *(unsigned int*)(sub + 0x2c70);
        *(unsigned short*)((zone + 0x2700) + 0xb4) = *(unsigned char*)(sub + 0x2c75);
        *(unsigned short*)((zone + 0x2700) + 0xb6) = *(unsigned char*)(sub + 0x2c76);
        unsigned char* z1840 = zone + 0x1840;
        *(unsigned int*)(z1840 + 0xb48) = *(unsigned int*)(sub + 0x2c80);
        *(unsigned int*)(z1840 + 0xb4c) = *(unsigned int*)(sub + 0x2c84);
        ClearAllTreasureMapUnknownBits_020116c8(gs);
        memcpy(GameState_GetPlayerLocation((char*)gs, 0), base + 0x2c54, 8);
        BackgroundLoader::RemoveLockGlobal();
        return 1;
    }
}
