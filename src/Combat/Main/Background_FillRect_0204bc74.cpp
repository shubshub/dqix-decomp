#include <globaldefs.h>

struct Struct_0204bc74 {
    char unknown_0_[0x14];
    unsigned short (*unknown_14_)[32];
};

// Main, originally func_0204bc74 (USA 0x0204bc74, EUR 0x0204bc84, JPN 0x0204ca94)
extern "C" ARM void Background_FillRect(struct TileMap0204bc74 *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette) {
    unsigned short (*rows)[32] = obj->rows;
    if (rows == 0) {
        return;
    }
    if (arg2 + arg4 <= 0 || arg3 + arg5 <= 0) {
        return;
    }
    if (arg2 >= 0x20 || arg3 >= 0x19) {
        return;
    }

    if (arg2 < 0) {
        arg4 = (short)(arg2 + arg4);
        arg2 = 0;
    } else if (arg2 + arg4 >= 0x20) {
        arg4 = (short)(0x20 - arg2);
    }

    if (arg3 < 0) {
        arg5 = arg5 + arg3;
        arg5 = (short)arg5;
        arg3 = 0;
    } else if (arg3 + arg5 >= 0x19) {
        arg5 = (short)(0x19 - arg3);
    }
    unsigned short *var1 = var0[arg3] + arg2;
    if (arg6 != 0xffff) {
        arg6 = arg6 << 12;
    } else {
        arg6 = 0;
    }
    arg1 = arg1 & 0xfff;
    arg1 |= arg6;

    short var2 = 0;
    short var3;
    while (var2 < arg5) {
        var3 = 0;
        while (var3 < arg4) {
            var1[var3] = arg1;
            var3 = var3 + 1;
        }
        var1 += 32;
        var2 = var2 + 1;
    }
}
