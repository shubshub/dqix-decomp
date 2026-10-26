#include <globaldefs.h>

typedef unsigned int u32;
typedef unsigned long long Type_020b11c8_2;

extern "C" void MIi_CpuClearFast(u32 value, void *dest, u32 size);

// USA: func_020b11c8
extern "C" ARM void func_020b11c8(void *pChar, int x, int y, int w, int h, u32 cl8, int bpp) {
    if ((w == 8) && (h == 8)) {
        MIi_CpuClearFast(cl8, pChar, (u32)(8 * bpp));
    } else {
        if (bpp == 4) {
            u32 mask;
            u32 data;
            u32 *var2;
            u32 *var3;

            {
                u32 var4 = (unsigned int)x * 4;
                u32 var5 = 32 - (w * 4 + var4);

                mask = (u32)(~0) >> var4;
                mask <<= var4 + var5;
                mask >>= var5;

                data = cl8 & mask;
                mask = ~mask;
            }

            var2 = (u32 *)pChar + y;
            var3 = var2 + h;
            for (; var2 < var3; var2++) {
                *var2 = (*var2 & mask) | data;
            }
        } else {
            u32 var6, var7;
            u32 var8, var9;

            {
                u32 x8 = (unsigned int)x * 8;
                u32 var11 = 64 - (w * 8 + x8);

                var6 = (u32)(~0) >> x8;
                if (var11 >= 32) {
                    const u32 var12 = var11 - 32;
                    var6 <<= (x8 + var12);
                    var6 >>= var12;
                } else {
                    var6 <<= x8;
                }

                var7 = (u32)(~0) << var11;
                if (x8 >= 32) {
                    const u32 var13 = x8 - 32;
                    var7 >>= (var13 + var11);
                    var7 <<= var13;
                } else {
                    var7 >>= var11;
                }

                var8 = cl8 & var6;
                var9 = cl8 & var7;

                var6 = ~var6;
                var7 = ~var7;
            }

            {
                u32 *var14 = (u32 *)((Type_020b11c8_2 *)pChar + y);
                u32 *const var15 = (u32 *)((Type_020b11c8_2 *)var14 + h);

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
