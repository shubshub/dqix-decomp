#include <globaldefs.h>

struct Struct_ov003_0217fa14 {
    signed char unknown_0_[4];
    int unknown_4_[2];
};

extern struct Struct_ov003_0217fa14 data_ov003_0217fa14;

extern "C" int Font_GetTextWidth(char* label, int extra);
extern "C" void func_0204f41c(void* obj, short x, short y, void* str, int d, int e, short* outA, short* outB, int zero);

// USA: func_ov003_02172618
extern "C" ARM void func_ov003_02172618(void* arg0, int arg1, char** arg2) {
    short var0;
    short var1;
    int var2[2] = {data_ov003_0217fa14.unknown_4_[0], arg1 + 0x16};
    for (int var3 = 0; var3 < 2; var3++) {
        char* var4 = arg2[var3];
        if (var4 == NULL) {
            continue;
        }
        int x = (0x100 - Font_GetTextWidth(label, 1)) >> 1;
        int ly = ys[i];
        func_0204f41c(canvas, x + 1, ly, label, 0xc, 0xe, &outA, &outB, 0);
        func_0204f41c(canvas, x, ly, label, 0xc, 0xf, &outA, &outB, 0);
    }
}
