#include <globaldefs.h>

struct Struct_0204cc68 {
    char pad0[8];
    unsigned char* buf;
    char unknown_c_[0x9c];
    short unknown_a8_;
    short unknown_aa_;
};

// USA: func_0204cc68
extern "C" ARM void func_0204cc68(Struct_0204cc68* wnd, int color, short arg2, short arg3, short x1, short arg5) {
    if (x1 < 0 || arg5 < 0) {
        return;
    }
    short h = (short)(wnd->unknown_aa_ << 3);
    short w = (short)(wnd->unknown_a8_ << 3);
    if (x1 > w) {
        return;
    }
    if (h < arg5) {
        return;
    }
    if (arg2 == x1 || arg3 == arg5) {
        return;
    }
    unsigned char hi = (color & 0xf) << 4;
    int lo = color & 0xf;
    for (short y = arg3; y < arg5; y++) {
        short var5 = (short)(y & 7) << 2;
        int row = (short)(y >> 3) * wnd->unknown_a8_;
        for (short x = arg2; x < x1; x++) {
            short tile = row + (short)(x >> 3);
            short idx = (short)((short)(tile << 5) + (short)((short)(x & 7) >> 1)) + var5;
            unsigned char* p = wnd->buf;
            if (x & 1) {
                p[idx] &= 0xf;
                p[idx] |= hi;
            } else {
                p[idx] &= 0xf0;
                p[idx] |= lo;
            }
        }
    }
}
