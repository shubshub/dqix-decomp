#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"

// Main, originally SetStructFieldsFromCode02028d68 (USA 0x02028d68, EUR 0x02028d78, JPN 0x020285b8)
ARM void GlyphMetrics_SetDisplayMode(int mode) {
    data_020ef74c.displayMode = mode;
    if (mode == 0) {
        data_020ef74c.rowHeight = 8;
        data_020ef74c.columnWidth = 8;
        return;
    }
    if ((unsigned int)(mode - 1) <= 1) {
        data_020ef74c.columnWidth = 6;
        data_020ef74c.rowHeight = 0xc;
        return;
    }
    if ((unsigned int)(mode - 3) <= 1) {
        data_020ef74c.columnWidth = 5;
        data_020ef74c.rowHeight = 0xa;
        return;
    }
    if ((unsigned int)(mode - 5) <= 1) {
        data_020ef74c.columnWidth = 6;
        data_020ef74c.rowHeight = 0xc;
    }
}
