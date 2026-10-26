#if !defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"
#include "Combat/MapDisplay.h"

int MessageSystem_GetInstance(void);
void OS_WaitVBlankIntr(void);
extern "C" void MapDisplay_DrawMapNameText(void* arg0, void* buf, int flag);
extern "C" int LoadToSubObjVRAM(void* buf, int a1, int a2);

// The map name's 18 OBJ tiles (8 x 16, 0x40 bytes each) in sub-screen OBJ VRAM; MapDisplay_LoadLocalMap saves the tile
// that was there (savedTiles) as each tile's background
enum {
    kNameTileCount = 18,
    kNameTileBytes = 0x40,
    kNameTilesVramOffset = 0x2c20,
    kMessageSystemTileBuffer = 0x60, // MessageSystem's tile buffer (MapDisplay_RefreshMemberPanel draws panels in it too)
};

// Main, originally InitAndCopyBuffer02023330 (USA 0x02023330, EUR 0x02023340; JPN not identified)
ARM int MapDisplay_UploadMapName(void* mapDisplay, int waitVBlank)
{
    void* messageSystem = (void*)MessageSystem_GetInstance();
    int offset = 0;
    int i = offset;
    void* tileBuffer = *(void**)((char*)messageSystem + kMessageSystemTileBuffer);
    int copySize = kNameTileBytes;
    while (i < kNameTileCount)
    {
        memcpy((char*)tileBuffer + offset, ((MapDisplay*)mapDisplay)->savedTiles, copySize);
        offset += kNameTileBytes;
        i++;
    }

    MapDisplay_DrawMapNameText(mapDisplay, tileBuffer, 0);
    if (waitVBlank != 0)
    {
        OS_WaitVBlankIntr();
    }

    CleanInvalidateCacheRange(tileBuffer, kNameTileCount * kNameTileBytes);
    LoadToSubObjVRAM(tileBuffer, kNameTilesVramOffset, kNameTileCount * kNameTileBytes);

    return 1;
}

#endif
