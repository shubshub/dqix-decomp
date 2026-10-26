#include <globaldefs.h>

typedef unsigned short u16;

extern "C" void func_020b1ff8(void *arg0, int areaWidth, int arg2, int arg3, int arg4, int arg5);

// USA: func_020b1f48
extern "C" ARM void func_020b1f48(void *arg0, int areaWidth, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    if (arg5 <= 32) {
        void *var0 = (u16 *)arg0 + (arg5 * arg4 + arg3);
        func_020b1ff8(var0, areaWidth, arg2, arg5, arg6, arg7);
    } else {
        const int var1 = arg3 + areaWidth;
        const int var2 = arg4 + arg2;
        const u16 var3 = (u16)(arg7 << 12);
        u16 *const var4 = (u16 *)arg0;
        int x, y;

        for (y = arg4; y < var2; ++y) {
            const int var7 = (y < 32) ? y : y + 32;
            u16 *var8 = var4 + var7 * 32;

            for (x = arg3; x < var1; ++x) {
                const int px = (x < 32) ? x : x + 32 * 31;
                *(var8 + px) = (u16)(var3 | arg6++);
            }
        }
    }
}
