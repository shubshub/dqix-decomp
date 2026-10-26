#include <globaldefs.h>

struct Struct_0205b1ac { int unknown_0_; short unknown_4_, unknown_6_, unknown_8_, unknown_a_; };
struct Struct_0205b890_2 { unsigned short unknown_0_, unknown_2_, unknown_4_; };
struct Struct_0205b890 {
    unsigned short unknown_0_, unknown_2_;
    Struct_0205b890_2* unknown_4_;
    Struct_0205b890_2* unknown_8_;
};

// Main, originally func_0205b890 (USA 0x0205b890, EUR 0x0205b8a0; JPN not identified)
extern "C" ARM void CanvasRect_InitFromSprite(Rect0205b1ac* rects, int capacity, CellRecord0205b890* record) {
    unsigned short count;
    int tile;
    Cell0205b890* cell;
    int baseTile;
    int baseX;
    int baseY;
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
            if (var12 == 0) { var9 = 8; var10 = 8; }
            else if (var12 == 1) { var9 = 16; var10 = 16; }
            else if (var12 == 2) { var9 = 32; var10 = 32; }
            else if (var12 == 3) { var9 = 64; var10 = 64; }
            break;
        case 1:
            if (var12 == 0) { var9 = 16; var10 = 8; }
            else if (var12 == 1) { var9 = 32; var10 = 8; }
            else if (var12 == 2) { var9 = 32; var10 = 16; }
            else if (var12 == 3) { var9 = 64; var10 = 32; }
            break;
        case 2:
            if (var12 == 0) { var9 = 8; var10 = 16; }
            else if (var12 == 1) { var9 = 8; var10 = 32; }
            else if (var12 == 2) { var9 = 16; var10 = 32; }
            else if (var12 == 3) { var9 = 32; var10 = 64; }
            break;
        }
        var1 = var2->unknown_4_ & 0x3ff;
        if (var6 == 0) {
            var4 = var7;
            var5 = var8;
            var3 = var1;
        }
        arg0[var6].unknown_0_ = (var1 - var3) << 5;
        var7 -= var4;
        var8 -= var5;
        arg0[var6].unknown_4_ = var7;
        arg0[var6].unknown_6_ = var8;
        arg0[var6].unknown_8_ = var9;
        arg0[var6].unknown_a_ = var10;
    }
}
