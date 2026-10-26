#include <globaldefs.h>


extern "C" ARM double sqrt(double x);
extern "C" ARM double func_02008f3c(double x);
extern "C" ARM double func_0200aae4(double x, int n);

extern const double data_020e6acc[];
extern const double data_020e6abc[];
extern const double data_020e6adc[];
extern float data_020eecc8;
extern int data_020f3390;

static const double zero = 0.0, one = 1.0, two = 2.0, two53 = 9007199254740992.0,
                    big = 1.0e300, tiny = 1.0e-300,
                    L1 = 5.99999999999994648725e-01,
                    L2 = 4.28571428578550184252e-01,
                    L3 = 3.33333329818377432918e-01,
                    L4 = 2.72728123808534006489e-01,
                    L5 = 2.30660745775561754067e-01,
                    L6 = 2.06975017800338417784e-01,
                    P1 = 1.66666666666666019037e-01,
                    P2 = -2.77777777770155933842e-03,
                    P3 = 6.61375632143793436117e-05,
                    P4 = -1.65339022054652515390e-06,
                    P5 = 4.13813679705723846039e-08,
                    lg2 = 6.93147180559945286227e-01,
                    lg2_h = 6.93147182464599609375e-01,
                    lg2_l = -1.90465429995776804525e-09,
                    ovt = 8.0085662595372944372e-0017,
                    cp = 9.61796693925975554329e-01,
                    cp_h = 9.61796700954437255859e-01,
                    cp_l = -7.02846165095275826516e-09,
                    ivln2 = 1.44269504088896338700e+00,
                    ivln2_h = 1.44269502162933349609e+00,
                    ivln2_l = 1.92596299112661746887e-08;

// USA: func_02005ea0
extern "C" ARM double func_02005ea0(double arg0, double arg1) {
    double var0, var1, var2, var3, var4, var5;
    double var6, var7, var8, var9, var10, var11, var12, var13, var14;
    int var15, var16, var17, var18, var19;
    int var20, var21, var22, var23;
    unsigned int var24, var25;

    var20 = ((int*)&arg0)[1];
    var24 = ((int*)&arg0)[0];
    var21 = ((int*)&arg1)[1];
    var25 = ((int*)&arg1)[0];
    var22 = var20 & 0x7fffffff;
    var23 = var21 & 0x7fffffff;

    if ((var23 | var25) == 0) {
        return one;
    }

    if (var22 > 0x7ff00000 || ((var22 == 0x7ff00000) && (var24 != 0)) || var23 > 0x7ff00000 ||
        ((var23 == 0x7ff00000) && (var25 != 0))) {
        return arg0 + arg1;
    }

    var18 = 0;
    if (var20 < 0) {
        if (var23 >= 0x43400000) {
            var18 = 2;
        } else if (var23 >= 0x3ff00000) {
            var17 = (var23 >> 20) - 0x3ff;
            if (var17 > 20) {
                var16 = var25 >> (52 - var17);
                if ((var16 << (52 - var17)) == var25) {
                    var18 = 2 - (var16 & 1);
                }
            } else if (var25 == 0) {
                var16 = var23 >> (20 - var17);
                if ((var16 << (20 - var17)) == var23) {
                    var18 = 2 - (var16 & 1);
                }
            }
        }
    }

    if (var25 == 0) {
        if (var23 == 0x7ff00000) {
            if (((var22 - 0x3ff00000) | var24) == 0) {
                return arg1 - arg1;
            } else if (var22 >= 0x3ff00000) {
                return (var21 >= 0) ? arg1 : zero;
            } else {
                return (var21 < 0) ? -arg1 : zero;
            }
        }
        if (var23 == 0x3ff00000) {
            if (var21 < 0) {
                return one / arg0;
            } else {
                return arg0;
            }
        }
        if (var21 == 0x40000000) {
            return arg0 * arg0;
        }
        if (hy == 0x3fe00000) {
            if (hx >= 0) {
                return sqrt(x);
            }
        }
    }

    var1 = func_02008f3c(arg0);
    if (var24 == 0) {
        if (var22 == 0x7ff00000 || var22 == 0 || var22 == 0x3ff00000) {
            var0 = var1;
            if (var21 < 0) {
                var0 = one / var0;
            }
            if (var20 < 0) {
                if (((var22 - 0x3ff00000) | var18) == 0) {
                    var0 = (var0 - var0) / (var0 - var0);
                } else if (var18 == 1) {
                    var0 = -var0;
                }
            }
            return var0;
        }
    }

    if ((((var20 >> 31) + 1) | var18) == 0) {
        data_020f3390 = 33;
        return data_020eecc8;
    }

    if (var23 > 0x41e00000) {
        if (var23 > 0x43f00000) {
            if (var22 <= 0x3fefffff) {
                return (var21 < 0) ? big * big : tiny * tiny;
            }
            if (var22 >= 0x3ff00000) {
                return (var21 > 0) ? big * big : tiny * tiny;
            }
        }
        if (var22 < 0x3fefffff) {
            return (var21 < 0) ? big * big : tiny * tiny;
        }
        if (var22 > 0x3ff00000) {
            return (var21 > 0) ? big * big : tiny * tiny;
        }
        var11 = arg0 - 1;
        var14 = (var11 * var11) * (0.5 - var11 * (0.3333333333333333333333 - var11 * 0.25));
        var12 = ivln2_h * var11;
        var13 = var11 * ivln2_l - var14 * ivln2;
        var7 = var12 + var13;
        ((int*)&var7)[0] = 0;
        var8 = var13 - (var7 - var12);
    } else {
        double var26, var27, var28, var29, var30;
        var19 = 0;
        if (var22 < 0x00100000) {
            var1 *= two53;
            var19 -= 53;
            var22 = ((int*)&var1)[1];
        }
        var19 += ((var22) >> 20) - 0x3ff;
        var16 = var22 & 0x000fffff;
        var22 = var16 | 0x3ff00000;
        if (var16 <= 0x3988e) {
            var17 = 0;
        } else if (var16 < 0xbb67a) {
            var17 = 1;
        } else {
            var17 = 0;
            var19 += 1;
            var22 -= 0x00100000;
        }
        ((int*)&var1)[1] = var22;

        var12 = var1 - data_020e6acc[var17];
        var13 = one / (var1 + data_020e6acc[var17]);
        var10 = var12 * var13;
        var27 = var10;
        ((int*)&var27)[0] = 0;
        var29 = zero;
        ((int*)&var29)[1] = ((var22 >> 1) | 0x20000000) + 0x00080000 + (var17 << 18);
        var30 = var1 - (var29 - data_020e6acc[var17]);
        var28 = var13 * ((var12 - var27 * var29) - var27 * var30);
        var26 = var10 * var10;
        var9 = var26 * var26 * (L1 + var26 * (L2 + var26 * (L3 + var26 * (L4 + var26 * (L5 + var26 * L6)))));
        var9 += var28 * (var27 + var10);
        var26 = var27 * var27;
        var29 = 3.0 + var26 + var9;
        ((int*)&var29)[0] = 0;
        var30 = var9 - ((var29 - 3.0) - var26);
        var12 = var27 * var29;
        var13 = var28 * var29 + var30 * var10;
        var4 = var12 + var13;
        ((int*)&var4)[0] = 0;
        var5 = var13 - (var4 - var12);
        var2 = cp_h * var4;
        var3 = cp_l * var4 + var5 * cp + data_020e6adc[var17];
        var11 = (double)var19;
        var7 = (((var2 + var3) + data_020e6abc[var17]) + var11);
        ((int*)&var7)[0] = 0;
        var8 = var3 - (((var7 - var11) - data_020e6abc[var17]) - var2);
    }

    var10 = one;
    if ((((var20 >> 31) + 1) | (var18 - 1)) == 0) {
        var10 = -one;
    }

    var6 = arg1;
    ((int*)&var6)[0] = 0;
    var5 = (arg1 - var6) * var7 + arg1 * var8;
    var4 = var6 * var7;
    var0 = var5 + var4;
    var16 = ((int*)&var0)[1];
    var15 = ((int*)&var0)[0];
    if (var16 >= 0x40900000) {
        if (((var16 - 0x40900000) | var15) != 0) {
            return var10 * big * big;
        } else {
            if (var5 + ovt > var0 - var4) {
                return var10 * big * big;
            }
        }
    } else if ((var16 & 0x7fffffff) >= 0x4090cc00) {
        if (((var16 - 0xc090cc00) | var15) != 0) {
            return var10 * tiny * tiny;
        } else {
            if (var5 <= var0 - var4) {
                return var10 * tiny * tiny;
            }
        }
    }

    var15 = var16 & 0x7fffffff;
    var17 = (var15 >> 20) - 0x3ff;
    var19 = 0;
    if (var15 > 0x3fe00000) {
        var19 = var16 + (0x00100000 >> (var17 + 1));
        var17 = ((var19 & 0x7fffffff) >> 20) - 0x3ff;
        var11 = zero;
        ((int*)&var11)[1] = (var19 & ~(0x000fffff >> var17));
        var19 = ((var19 & 0x000fffff) | 0x00100000) >> (20 - var17);
        if (var16 < 0) {
            var19 = -var19;
        }
        var4 -= var11;
    }
    var11 = var5 + var4;
    ((int*)&var11)[0] = 0;
    var12 = var11 * lg2_h;
    var13 = (var5 - (var11 - var4)) * lg2 + var11 * lg2_l;
    var0 = var12 + var13;
    var14 = var13 - (var0 - var12);
    var11 = var0 * var0;
    var7 = var0 - var11 * (P1 + var11 * (P2 + var11 * (P3 + var11 * (P4 + var11 * P5))));
    var9 = (var0 * var7) / (var7 - two) - (var14 + var0 * var14);
    var0 = one - (var9 - var0);
    var16 = ((int*)&var0)[1];
    var16 += (var19 << 20);
    if ((var16 >> 20) <= 0) {
        var0 = func_0200aae4(var0, var19);
    } else {
        ((int*)&var0)[1] += (var19 << 20);
    }
    return var10 * var0;
}
