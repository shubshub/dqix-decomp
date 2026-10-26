#include <globaldefs.h>
struct Rect0205b1ac { int offset; short x, y, w, h; };
struct Canvas0205b530 { unsigned char* pixels; Rect0205b1ac* rects; unsigned char count; };
extern "C" Rect0205b1ac* func_0205b1ac(Rect0205b1ac*, unsigned int, int, int);
// Main, originally func_0205b530 (USA 0x0205b530, EUR 0x0205b540, JPN 0x0205c830)
extern "C" ARM void Canvas_DrawTile(Canvas0205b530* self, unsigned char* src, short x, short y) {
    if (!src) return;
    unsigned char count = self->count;
    unsigned char* pixels = self->pixels;
    Rect0205b1ac* rects = self->rects;
    short px;
    for (short row = 0; row < 8; src += 4, y++, row++) {
        px = x;
        for (short col = 0; col < 8; px++, col++) {
            Rect0205b1ac* rect = func_0205b1ac(rects, count, px, y);
            if (rect) {
                short rx = px - rect->x;
                short ry = y - rect->y;
                short width = rect->w >> 3;
                unsigned char* base = pixels + rect->offset;
                short var11 = (short)(rx & 7) >> 1;
                short var12 = ry & 7;
                int var13;
                unsigned char* tile = base + (((short)(ry >> 3) * width + (rx >> 3)) << 5);
                var13 = (var12 << 2) + var11;
                int value = src[col >> 1];
                unsigned char nibble;
                if (rx & 1) {
                    if (col & 1) nibble = value & 0xf0; else nibble = (value << 4) & 0xf0;
                    if (nibble) { tile[var13] &= 15; tile[var13] |= nibble; }
                } else {
                    if (col & 1) nibble = (value >> 4) & 15; else nibble = value & 15;
                    if (nibble) { tile[var13] &= 0xf0; tile[var13] |= nibble; }
                }
            }
        }
    }
}
