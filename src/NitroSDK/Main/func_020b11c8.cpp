#include <globaldefs.h>

typedef unsigned int Type_020b11c8;
typedef unsigned long long Type_020b11c8_2;

extern "C" void MIi_CpuClearFast(u32 value, void *dest, u32 size);

// USA: func_020b11c8
extern "C" ARM void func_020b11c8(void *pChar, int x, int y, int w, int h, u32 cl8, int bpp) {
    if ((w == 8) && (h == 8)) {
        MIi_CpuClearFast(cl8, pChar, (u32)(8 * bpp));
    } else {
        if (arg6 == 4) {
            Type_020b11c8 var0;
            Type_020b11c8 var1;
            Type_020b11c8 *var2;
            Type_020b11c8 *var3;

            {
                Type_020b11c8 var4 = (unsigned int)arg1 * 4;
                Type_020b11c8 var5 = 32 - (arg3 * 4 + var4);

                var0 = (Type_020b11c8)(~0) >> var4;
                var0 <<= var4 + var5;
                var0 >>= var5;

                var1 = arg5 & var0;
                var0 = ~var0;
            }

            var2 = (Type_020b11c8 *)arg0 + arg2;
            var3 = var2 + arg4;
            for (; var2 < var3; var2++) {
                *var2 = (*var2 & var0) | var1;
            }
        } else {
            Type_020b11c8 var6, var7;
            Type_020b11c8 var8, var9;

            {
                Type_020b11c8 var10 = (unsigned int)arg1 * 8;
                Type_020b11c8 var11 = 64 - (arg3 * 8 + var10);

                var6 = (Type_020b11c8)(~0) >> var10;
                if (var11 >= 32) {
                    const Type_020b11c8 var12 = var11 - 32;
                    var6 <<= (var10 + var12);
                    var6 >>= var12;
                } else {
                    var6 <<= var10;
                }

                var7 = (Type_020b11c8)(~0) << var11;
                if (var10 >= 32) {
                    const Type_020b11c8 var13 = var10 - 32;
                    var7 >>= (var13 + var11);
                    var7 <<= var13;
                } else {
                    var7 >>= var11;
                }

                var8 = arg5 & var6;
                var9 = arg5 & var7;

                var6 = ~var6;
                var7 = ~var7;
            }

            {
                Type_020b11c8 *var14 = (Type_020b11c8 *)((Type_020b11c8_2 *)arg0 + arg2);
                Type_020b11c8 *const var15 = (Type_020b11c8 *)((Type_020b11c8_2 *)var14 + arg4);

                while (var14 < var15) {
                    *var14 = (*var14 & var6) | var8;
                    var14++;
                    *var14 = (*var14 & var7) | var9;
                    var14++;
                }
            }
        }
    }
}
