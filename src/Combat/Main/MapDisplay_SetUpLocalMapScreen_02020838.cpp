#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "World/Zone3D.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void G2S_SetBG0Control(int screenSize, int colorMode, int screenBase, int charBase, int extPaletteSlot);
extern "C" void G2S_SetBG1Control(int screenSize, int colorMode, int screenBase, int charBase, int extPaletteSlot);

// Sub-screen DISPCNT bits (GBATEK): the visible layers are bits 8-12 (BG0-BG3, OBJ); bit 4 is 1D OBJ tile
// mapping and bits 20-21 its boundary (0 = 32 bytes).
enum {
    kVisibleLayersMask = 0x1f00,
    kVisibleBg0AndObj = 0x1100,
    kVisibleBg0Bg1AndObj = 0x1300,
    kObjMappingMask = 0x00300010,
    kObjMapping1D32 = 0x10,
};

// Main, originally func_02020838 (USA 0x02020838, EUR 0x02020848, JPN 0x0202045c)
extern "C" ARM void MapDisplay_SetUpLocalMapScreen(MapDisplay* unusedContext) {
    volatile unsigned int* dispcnt = &DISPCNTSUB;
    // The zone's entry in the zone table (Zone3D::SwitchZone sets it with ZoneTable_FindEntry); map type 0 gets
    // one map layer, the others two (BG0 is 512 wide)
    Zone3D_StructPtr_8* zoneEntry = Zone3D_GetInstance()->pUnknownStruct_8_;

    DisableSubBGVRAMBanks();
    DisableSubObjVRAMBanks();
    GXS_SetGraphicsMode(0);
    MapVRAMBanksToSubBG(VRAM_BANK_H);

    if (zoneEntry->unknown_c_low_ == 0) {
        *dispcnt = (*dispcnt & ~kVisibleLayersMask) | kVisibleBg0AndObj;
        G2S_SetBG0Control(0, 0, 0xf, 0, 0);
        G2S_SetBG1Control(0, 0, 0x10, 0, 0);
    } else {
        *dispcnt = (*dispcnt & ~kVisibleLayersMask) | kVisibleBg0Bg1AndObj;
        G2S_SetBG0Control(1, 0, 0xe, 0, 0);
        G2S_SetBG1Control(0, 0, 0xd, 0, 0);
    }

    MapVRAMBanksToSubObj(VRAM_BANK_I);

    *dispcnt = (*dispcnt & ~kObjMappingMask) | kObjMapping1D32;

    // Layer priorities: BG2 in front, then BG0, BG1, BG3
    unsigned short* bgControl = (unsigned short*)&BG0CNTSUB;
    bgControl[0] = (bgControl[0] & ~BGCNT_MASK_PRIORITY) | 1;
    bgControl[1] = (bgControl[1] & ~BGCNT_MASK_PRIORITY) | 2;
    bgControl[2] = (bgControl[2] & ~BGCNT_MASK_PRIORITY);
    bgControl[3] = (bgControl[3] & ~BGCNT_MASK_PRIORITY) | 3;
}
