#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

// The NitroSDK G2S_SetBG0Control inline: keeps priority and mosaic, sets the rest of the sub-screen BG0 control.
// Main, originally SetSubBg0Control02020968 (USA 0x02020968, EUR 0x02020978, JPN 0x0202058c)
ARM void G2S_SetBG0Control(int screenSize, int colorMode, int screenBase, int charBase, int extPaletteSlot) {
    unsigned short* reg = (unsigned short*)&BG0CNTSUB;
    *reg = (*reg & (BGCNT_MASK_PRIORITY | BGCNT_MASK_MOSAIC)) | (screenSize << 0xe) | (colorMode << 0x7) | (screenBase << 0x8) | (charBase << 0x2) | (extPaletteSlot << 0xd);
}
