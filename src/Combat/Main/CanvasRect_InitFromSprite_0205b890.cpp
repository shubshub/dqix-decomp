#include <globaldefs.h>

struct Rect0205b1ac { int offset; short x, y, width, height; };
struct Struct_0205b890_2 { unsigned short y, x, attributes; };
struct CellRecord0205b890 {
    unsigned short count, flags;
    Struct_0205b890_2* cells;
    Struct_0205b890_2* copy;
};

// Main, originally func_0205b890 (USA 0x0205b890, EUR 0x0205b8a0; JPN not identified)
extern "C" ARM void CanvasRect_InitFromSprite(Rect0205b1ac* rects, int capacity, CellRecord0205b890* record) {
    unsigned short count;
    int tile;
    Struct_0205b890_2* cell;
    int var3;
    int var4;
    int var5;
    unsigned short i;
    short x;
    short y;
    short width;
    short height;
    if (!rects || !record) return;
    count = record->count;
    if (capacity < count) return;
    cell = record->copy;
    if (!cell) return;
    for (i = 0; i < count; cell++, i++) {
        x = cell->x & 0x1f;
        y = cell->y & 0xf;
        unsigned short shape = (cell->y & 0xc000) >> 14;
        unsigned short size = (cell->x & 0xc000) >> 14;
        switch (shape) {
        case 0:
            if (size == 0) { width = 8; height = 8; }
            else if (size == 1) { width = 16; height = 16; }
            else if (size == 2) { width = 32; height = 32; }
            else if (size == 3) { width = 64; height = 64; }
            break;
        case 1:
            if (size == 0) { width = 16; height = 8; }
            else if (size == 1) { width = 32; height = 8; }
            else if (size == 2) { width = 32; height = 16; }
            else if (size == 3) { width = 64; height = 32; }
            break;
        case 2:
            if (size == 0) { width = 8; height = 16; }
            else if (size == 1) { width = 8; height = 32; }
            else if (size == 2) { width = 16; height = 32; }
            else if (size == 3) { width = 32; height = 64; }
            break;
        }
        tile = cell->attributes & 0x3ff;
        if (i == 0) {
            var4 = x;
            var5 = y;
            var3 = tile;
        }
        rects[i].offset = (tile - var3) << 5;
        x -= var4;
        y -= var5;
        rects[i].x = x;
        rects[i].y = y;
        rects[i].width = width;
        rects[i].height = height;
    }
}
