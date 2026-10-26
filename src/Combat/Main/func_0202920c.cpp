#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"

#if defined(jpn)
#define func_0202920c func_02028dc4
#endif

// USA: func_0202920c
extern "C" ARM void func_0202920c(int color, int x, int y, int w, int h) {
    if (glyphBitmapContext.buffer == 0) return;
    if (x + w < 0) return;
    if (y + h < 0) return;
    if (x >= 0x100 || y >= 0xc0) return;
    if (x < 0) {
        w = x + w;
        x = 0;
    }
    if (x + w >= 0x100) w = 0xff - x;
    if (y < 0) {
        h = y + h;
        y = 0;
    }
    if (y + h >= 0xc0) h = 0xbf - y;

    int var0;
    unsigned char var1;
    int var2;
    unsigned char* row;
    int i;
    unsigned char* p;
    int j;

    var2 = color & 0xff;
    var1 = (var2 << 4) & 0xff;
    row = (unsigned char*)glyphBitmapContext.buffer + y * 0x80 + x / 2;

    for (i = 0; i < h; i++) {
        p = row;
        var0 = x;
        for (j = 0; j < w; j++) {
            if (var0 & 1) {
                *p = (*p & 0xf) | var1;
                p++;
            } else {
                *p = (*p & 0xf0) | var2;
            }
            var0++;
        }
        row += 0x80;
    }
}
