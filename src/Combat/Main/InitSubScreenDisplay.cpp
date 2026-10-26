#include <globaldefs.h>

extern "C" void DisableSubObjVRAMBanks(void);
extern "C" int DisableSubBGVRAMBanks(void);
void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
void G2S_SetBG0Control(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void G2S_SetBG1Control(int screenSize, int colorMode, int screenBase, int charBase, int bit13);

// USA: func_020209d0
ARM void InitSubScreenDisplay_020209d0(void* context) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    GXS_SetGraphicsMode(0);

    *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
    MapVRAMBanksToSubObj(0x100);

    *dispcnt = (*dispcnt & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubBG(0x80);

    G2S_SetBG0Control(0, 0, 0xe, 0, 0);
    G2S_SetBG1Control(0, 0, 0xf, 0, 0);

    unsigned short* bgcnt = (unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3) | 1;
    bgcnt[1] = (bgcnt[1] & ~3);
    bgcnt[2] = (bgcnt[2] & ~3) | 2;
    bgcnt[3] = (bgcnt[3] & ~3) | 3;
}
