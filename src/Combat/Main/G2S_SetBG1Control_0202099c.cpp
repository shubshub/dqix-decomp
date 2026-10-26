#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

// The NitroSDK G2S_SetBG1Control inline: keeps priority and mosaic, sets the rest of the sub-screen BG1 control.
// Main, originally SetSubBg1Control0202099c (USA 0x0202099c, EUR 0x020209ac, JPN 0x020205c0)
ARM void G2S_SetBG1Control(int screenSize, int colorMode, int screenBase, int charBase, int extPaletteSlot) {
    unsigned short* reg = (unsigned short*)&BG1CNTSUB;
    *reg = (*reg & (BGCNT_MASK_PRIORITY | BGCNT_MASK_MOSAIC)) | (screenSize << 0xe) | (colorMode << 0x7) | (screenBase << 0x8) | (charBase << 0x2) | (extPaletteSlot << 0xd);
}
