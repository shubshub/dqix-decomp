#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

struct Struct_02107800_2 {
#if defined(jpn)
    char unknown0[0x14];
    FontGlyphTable* unknown_14_;
    char unknown18[8];
    FontGlyphTable* unknown_20_;
    FontGlyphTable* unknown_24_;
    FontGlyphTable* unknown_28_;
#else
    char unknown0[0x10];
    FontGlyphTable* unknown_10_;
#endif
};

extern Struct_02107800_2 data_02107800;

// Main, originally GetFontGlyphTable_020429bc (USA 0x020429bc, EUR 0x020429cc, JPN 0x02042e30)
extern "C" ARM FontGlyphTable* Font_GetGlyphTable(int pixelSize) {
    FontGlyphTable* table = NULL;
#if defined(jpn)
    switch (pixelSize) {
    case 6: table = data_02107800.unknown_14_; break;
    case 8: table = data_02107800.unknown_20_; break;
    case 10: table = data_02107800.unknown_24_; break;
    case 12: table = data_02107800.unknown_28_; break;
    }
#else
    if (pixelSize == 8) table = data_02107800.unknown_10_;
#endif
    return table;
}
