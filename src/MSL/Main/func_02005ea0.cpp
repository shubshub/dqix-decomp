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
extern "C" ARM double func_02005ea0(double x, double y) {
    double z, ax, var2, var3, var4, var5;
    double var6, var7, t2, r, s, t, u, v, w;
    int i, j, k, var18, n;
    int var20, var21, var22, var23;
    unsigned int var24, var25;

    var20 = ((int*)&x)[1];
    var24 = ((int*)&x)[0];
    var21 = ((int*)&y)[1];
    var25 = ((int*)&y)[0];
    var22 = var20 & 0x7fffffff;
    var23 = var21 & 0x7fffffff;

    if ((var23 | var25) == 0) {
        return one;
    }

    if (var22 > 0x7ff00000 || ((var22 == 0x7ff00000) && (var24 != 0)) || var23 > 0x7ff00000 ||
        ((var23 == 0x7ff00000) && (var25 != 0))) {
        return x + y;
    }

    var18 = 0;
    if (var20 < 0) {
        if (var23 >= 0x43400000) {
            var18 = 2;
        } else if (var23 >= 0x3ff00000) {
            k = (var23 >> 20) - 0x3ff;
            if (k > 20) {
                j = var25 >> (52 - k);
                if ((j << (52 - k)) == var25) {
                    var18 = 2 - (j & 1);
                }
            } else if (var25 == 0) {
                j = var23 >> (20 - k);
                if ((j << (20 - k)) == var23) {
                    var18 = 2 - (j & 1);
                }
            }
        }
    }

    if (var25 == 0) {
        if (var23 == 0x7ff00000) {
            if (((var22 - 0x3ff00000) | var24) == 0) {
                return y - y;
            } else if (var22 >= 0x3ff00000) {
                return (var21 >= 0) ? y : zero;
            } else {
                return (var21 < 0) ? -y : zero;
            }
        }
        if (var23 == 0x3ff00000) {
            if (var21 < 0) {
                return one / x;
            } else {
                return x;
            }
        }
        if (var21 == 0x40000000) {
            return x * x;
        }
        if (var21 == 0x3fe00000) {
            if (var20 >= 0) {
                return sqrt(x);
            }
        }
    }

    ax = func_02008f3c(x);
    if (var24 == 0) {
        if (var22 == 0x7ff00000 || var22 == 0 || var22 == 0x3ff00000) {
            z = ax;
            if (var21 < 0) {
                z = one / z;
            }
            if (var20 < 0) {
                if (((var22 - 0x3ff00000) | var18) == 0) {
                    z = (z - z) / (z - z);
                } else if (var18 == 1) {
                    z = -z;
                }
            }
            return z;
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
        t = x - 1;
        w = (t * t) * (0.5 - t * (0.3333333333333333333333 - t * 0.25));
        u = ivln2_h * t;
        v = t * ivln2_l - w * ivln2;
        var7 = u + v;
        ((int*)&var7)[0] = 0;
        t2 = v - (var7 - u);
    } else {
        double s2, var27, var28, var29, var30;
        n = 0;
        if (var22 < 0x00100000) {
            ax *= two53;
            n -= 53;
            var22 = ((int*)&ax)[1];
        }
        n += ((var22) >> 20) - 0x3ff;
        j = var22 & 0x000fffff;
        var22 = j | 0x3ff00000;
        if (j <= 0x3988e) {
            k = 0;
        } else if (j < 0xbb67a) {
            k = 1;
        } else {
            k = 0;
            n += 1;
            var22 -= 0x00100000;
        }
        ((int*)&ax)[1] = var22;

        u = ax - data_020e6acc[k];
        v = one / (ax + data_020e6acc[k]);
        s = u * v;
        var27 = s;
        ((int*)&var27)[0] = 0;
        var29 = zero;
        ((int*)&var29)[1] = ((var22 >> 1) | 0x20000000) + 0x00080000 + (k << 18);
        var30 = ax - (var29 - data_020e6acc[k]);
        var28 = v * ((u - var27 * var29) - var27 * var30);
        s2 = s * s;
        r = s2 * s2 * (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + s2 * L6)))));
        r += var28 * (var27 + s);
        s2 = var27 * var27;
        var29 = 3.0 + s2 + r;
        ((int*)&var29)[0] = 0;
        var30 = r - ((var29 - 3.0) - s2);
        u = var27 * var29;
        v = var28 * var29 + var30 * s;
        var4 = u + v;
        ((int*)&var4)[0] = 0;
        var5 = v - (var4 - u);
        var2 = cp_h * var4;
        var3 = cp_l * var4 + var5 * cp + data_020e6adc[k];
        t = (double)n;
        var7 = (((var2 + var3) + data_020e6abc[k]) + t);
        ((int*)&var7)[0] = 0;
        t2 = var3 - (((var7 - t) - data_020e6abc[k]) - var2);
    }

    s = one;
    if ((((var20 >> 31) + 1) | (var18 - 1)) == 0) {
        s = -one;
    }

    var6 = y;
    ((int*)&var6)[0] = 0;
    var5 = (y - var6) * var7 + y * t2;
    var4 = var6 * var7;
    z = var5 + var4;
    j = ((int*)&z)[1];
    i = ((int*)&z)[0];
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0) {
            return s * big * big;
        } else {
            if (var5 + ovt > z - var4) {
                return s * big * big;
            }
        }
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - 0xc090cc00) | i) != 0) {
            return s * tiny * tiny;
        } else {
            if (var5 <= z - var4) {
                return s * tiny * tiny;
            }
        }
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;
    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;
        t = zero;
        ((int*)&t)[1] = (n & ~(0x000fffff >> k));
        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0) {
            n = -n;
        }
        var4 -= t;
    }
    t = var5 + var4;
    ((int*)&t)[0] = 0;
    u = t * lg2_h;
    v = (var5 - (t - var4)) * lg2 + t * lg2_l;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    var7 = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
    r = (z * var7) / (var7 - two) - (w + z * w);
    z = one - (r - z);
    j = ((int*)&z)[1];
    j += (n << 20);
    if ((j >> 20) <= 0) {
        z = func_0200aae4(z, n);
    } else {
        ((int*)&z)[1] += (n << 20);
    }
    return s * z;
}
