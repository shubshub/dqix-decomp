#include <globaldefs.h>

struct Struct_ov003_02169674 {
    short originX;
    short originY;
    signed char count;
    char pad5;
    short* unknown_8_;
    short* unknown_c_;
    short* unknown_10_;
    short* unknown_14_;
};

// USA: func_ov003_02169674
extern "C" ARM int func_ov003_02169674(int unused, int x, int y, Struct_ov003_02169674* s) {
    int var0 = x - s->originX;
    int var1 = y - s->originY;
    short* var2 = s->unknown_8_;
    short* var3 = s->unknown_c_;
    short* var4 = s->unknown_10_;
    short* var5 = s->unknown_14_;
    int count = s->count;
    for (int i = 0; i < count; i++) {
        int var8 = var2[i] + var4[i];
        int var9 = var3[i] + var5[i];
        if (var0 < var2[i]) continue;
        if (var0 > var8) continue;
        if (var1 < var3[i]) continue;
        if (var1 <= var9) return i;
    }
    return -1;
}
