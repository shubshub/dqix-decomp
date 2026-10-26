#include <globaldefs.h>

struct Struct_0204e1c8 {
    char pad0[8];
    unsigned char* buf;
    char unknown_c_[0xa8 - 0xc];
    short cols;
    short rows;
};

// USA: func_0204e1c8
extern "C" ARM void func_0204e1c8(Struct_0204e1c8* wnd, unsigned char* src, short x, short y, short w, short h, unsigned char arg6, unsigned char arg7) {
    int var0;
    unsigned char var1;
    short px;
    short ty;
    short j;
    short i;
    if (src == NULL) {
        return;
    }
    short cols = wnd->cols;
    short rows = wnd->rows;
    for (j = 0; j < h; j++) {
        short dy = y & 7;
        short var9 = dy << 2;
        ty = y >> 3;
        bool var10 = ty >= 0 && ty < rows;
        ty *= wnd->cols;
        px = x;
        for (i = 0; i < w; i++) {
            var0 = px;
            short tx = var0 >> 3;
            bool var12 = tx >= 0 && tx < cols;
            short tile = ty + tx;
            bool draw = var12 | var10;
            short off = tile * 32;
            off += (short)(var0 & 7) >> 1;
            off += var9;
            var1 = wnd->buf[off];
            if (x & 1) {
                if (i & 1) {
                    if (draw) {
                        unsigned char v = *src & arg6;
                        if (v) {
                            v >>= 4;
                            var1 &= 0xf0;
                            var1 |= v;
                        }
                        wnd->buf[off] = var1;
                    }
                    src++;
                } else {
                    if (draw) {
                        unsigned char v = *src & arg7;
                        if (v) {
                            v <<= 4;
                            var1 &= 0x0f;
                            var1 |= v;
                        }
                        wnd->buf[off] = var1;
                    }
                }
            } else {
                if (i & 1) {
                    if (draw) {
                        unsigned char v = *src & arg6;
                        if (v) {
                            var1 &= 0x0f;
                            var1 |= v;
                        }
                        wnd->buf[off] = var1;
                    }
                    src++;
                } else {
                    if (draw) {
                        unsigned char v = *src & arg7;
                        if (v) {
                            var1 &= 0xf0;
                            var1 |= v;
                        }
                        wnd->buf[off] = var1;
                    }
                }
            }
            px++;
        }
        y++;
    }
}
