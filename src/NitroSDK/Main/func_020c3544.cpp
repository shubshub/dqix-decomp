#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int arg0, unsigned int arg1);
extern short data_020ed554[];

// USA: func_020c3544
extern "C" ARM int func_020c3544(int dx, int dy) {
    int num, var1, base, var3;

    if (dx > 0) {
        if (dy > 0) {
            if (dy > dx) {
                num = dx; var1 = dy; base = 0; var3 = 1;
            } else {
                if (dy < dx) {
                    num = dy; var1 = dx; base = 0x4000; var3 = 0;
                } else {
                    return 0x2000;
                }
            }
        } else {
            if (dy < 0) {
                int var4 = -dy;
                if (var4 < dx) {
                    num = var4; var1 = dx; base = 0x4000; var3 = 1;
                } else {
                    if (var4 > dx) {
                        num = dx; var1 = var4; base = 0x8000; var3 = 0;
                    } else {
                        return 0x6000;
                    }
                }
            } else {
                return 0x4000;
            }
        }
    } else {
        if (dx < 0) {
            int var5 = -dx;
            if (dy < 0) {
                int var6 = -dy;
                if (var6 > var5) {
                    num = var5; var1 = var6; base = -0x8000; var3 = 1;
                } else {
                    if (var6 < var5) {
                        num = var6; var1 = var5; base = -0x4000; var3 = 0;
                    } else {
                        return 0xa000;
                    }
                }
            } else {
                if (dy > 0) {
                    if (dy < var5) {
                        num = dy; var1 = var5; base = -0x4000; var3 = 1;
                    } else {
                        if (dy > var5) {
                            num = var5; var1 = dy; base = 0; var3 = 0;
                        } else {
                            return 0xe000;
                        }
                    }
                } else {
                    return 0xc000;
                }
            }
        } else {
            return (dy >= 0) ? 0 : 0x8000;
        }
    }

    if (var1 == 0) {
        return 0;
    }
    if (var3) {
        int val = data_020ed554[fix32_Divide(num, var1) >> 5];
        return (unsigned short)(base + val);
    } else {
        int val = data_020ed554[fix32_Divide(num, var1) >> 5];
        return (unsigned short)(base - val);
    }
}
