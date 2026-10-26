#include <globaldefs.h>

// One cell of a pixel canvas (CanvasRect_InitFromSprite fills it from a cell record): its tile offset and rectangle
struct Struct02020520 {
    int offset;
    short x;
    short y;
    short width;
    short height;
};

// Main, originally ClearStruct02020520 (USA 0x02020520, EUR 0x02020530, JPN 0x0202016c)
extern "C" ARM void GlyphDestinationRect_Clear(struct Struct02020520* cell) {
    cell->offset = 0;
    cell->x = 0;
    cell->y = 0;
    cell->width = 0;
    cell->height = 0;
}
