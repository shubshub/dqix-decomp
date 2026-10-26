#include <globaldefs.h>

struct Struct_0204e038 {
    char pad0[8];
    unsigned char* buf;
    char unknown_c_[0xa8 - 0xc];
    short cols;
    short rows;
};

// USA: func_0204e038
extern "C" ARM void func_0204e038(Struct_0204e038* wnd, unsigned char* bits, short x, short y, short w, short h, unsigned char arg6, unsigned char arg7) {
    short tx;
    short ty;
    unsigned char bit;
    short j;
    short i;
    if (bits == NULL) {
        return;
    }
    short cols = wnd->cols;
    short rows = wnd->rows;
    bit = 0;
    for (j = 0; j < h; j++) {
        short var7 = y + j;
        short var8 = (var7 & 7) << 2;
        ty = var7 >> 3;
        bool var9 = ty >= 0 && ty < rows;
        ty *= wnd->cols;
        for (i = 0; i < w; i++) {
            if (var9 && (*bits & (1 << bit))) {
                int px = (short)(x + i);
                int dx = px & 7;
                tx = px >> 3;
                bool var12 = tx >= 0 && tx < cols;
                bool draw = var12 | var9;
                if (draw) {
                    short off = var8 + (tx + ty) * 32 + (dx >> 1);
                    unsigned char* buf = wnd->buf;
                    if (px & 1) {
                        buf[off] &= 0x0f;
                        buf[off] |= arg6;
                    } else {
                        buf[off] &= 0xf0;
                        buf[off] |= arg7;
                    }
                }
            }
            bit++;
            if (bit >= 8) {
                bit = 0;
                bits++;
            }
        }
    }
}
