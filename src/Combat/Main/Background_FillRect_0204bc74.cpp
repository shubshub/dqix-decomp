#include <globaldefs.h>
#include "Graphics/Background.h"

// Main, originally func_0204bc74 (USA 0x0204bc74, EUR 0x0204bc84, JPN 0x0204ca94)
extern "C" ARM void Background_FillRect(struct BackgroundGraphics *layer, unsigned short tile, int x, int y, int width, int height, unsigned short palette) {
    unsigned short (*map)[BackgroundMap_Columns] = (unsigned short (*)[BackgroundMap_Columns])layer->map_;
    if (map == 0) {
        return;
    }
    if (x + width <= 0 || y + height <= 0) {
        return;
    }
    if (x >= BackgroundMap_Columns || y >= BackgroundMap_Rows) {
        return;
    }

    if (x < 0) {
        width = (short)(x + width);
        x = 0;
    } else if (x + width >= BackgroundMap_Columns) {
        width = (short)(BackgroundMap_Columns - x);
    }

    if (y < 0) {
        height = height + y;
        height = (short)height;
        y = 0;
    } else if (y + height >= BackgroundMap_Rows) {
        height = (short)(BackgroundMap_Rows - y);
    }
    unsigned short *row = map[y] + x;
    if (palette != BackgroundPalette_Keep) {
        palette = palette << 12;
    } else {
        arg6 = 0;
    }
    arg1 = arg1 & 0xfff;
    arg1 |= arg6;

    short j = 0;
    short i;
    while (j < height) {
        i = 0;
        while (i < width) {
            row[i] = tile;
            i = i + 1;
        }
        row += BackgroundMap_Columns;
        j = j + 1;
    }
}
