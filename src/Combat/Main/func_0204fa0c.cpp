#include <globaldefs.h>
struct Struct_0204fa0c { char unknown0[0xc5]; unsigned char flags; };
extern "C" char* func_020421b0(int);
extern "C" void func_0204e1c8(Struct_0204fa0c*, char*, int, int, int, int, int, int);
// USA: func_0204fa0c
extern "C" ARM void func_0204fa0c(Struct_0204fa0c* window, short x, short y) {
    if (!(window->flags & 0x40)) return;
    short left = x - 6;
    short top = y - 2;
    short right = left + 8;
    short bottom = top + 8;
    short xs[4];
    short ys[4];
    xs[0] = left;
    xs[2] = left;
    xs[1] = right;
    xs[3] = right;
    ys[0] = top;
    ys[1] = top;
    ys[2] = bottom;
    ys[3] = bottom;
    unsigned char var6 = 16;
    for (unsigned char i = 0; i < 4; ++i) {
        char* graphic = func_020421b0(var6);
        if (graphic) {
            func_0204e1c8(window, graphic, xs[i], ys[i], 8, 8, 0xf0, 15);
        }
        ++var6;
    }
}
