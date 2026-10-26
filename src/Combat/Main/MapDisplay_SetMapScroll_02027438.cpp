#include <globaldefs.h>
#include "Combat/MapDisplay.h"

class FlagWord02046708;

FlagWord02046708* GlobalFlags_GetInstance();
bool FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);

// Sub engine BG0HOFS (low half) and BG0VOFS (high half) in one write
#define BG0OFS_SUB (*(volatile unsigned int*)0x4001010)

#define PIXEL_WITHIN_TILE(v) ((v) < 0 ? (v) % 8 + 8 : (v) % 8)

// Main, originally func_02027438 (USA 0x02027438, EUR 0x02027448, JPN 0x02026d9c)
extern "C" ARM void MapDisplay_SetMapScroll(MapDisplay* display) {
    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 0x41)) {
        return;
    }
    switch (display->displayMode) {
    case 0: {
        int x = display->screenX;
        int phaseX = PIXEL_WITHIN_TILE(x);
        int y = display->screenY;
        int phaseY = PIXEL_WITHIN_TILE(y);
        BG0OFS_SUB = ((phaseX + 0x80) & 0x1ff) | (((phaseY + 0x20) << 16) & 0x1ff0000);
        break;
    }
    case 2:
    case 3: {
        int y = display->screenY;
        int phaseY = PIXEL_WITHIN_TILE(y);
        BG0OFS_SUB = ((phaseY + 0x20) << 16) & 0x1ff0000;
        break;
    }
    case 4: {
        int y = display->screenY;
        int phaseY = PIXEL_WITHIN_TILE(y);
        BG0OFS_SUB = ((0x20 - phaseY) << 16) & 0x1ff0000;
        break;
    }
    default:
        BG0OFS_SUB = 0;
        break;
    }
}
