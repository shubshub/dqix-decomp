#include <globaldefs.h>

extern "C" double func_02008f3c(double x);
extern "C" int func_02007a10(double*, double*, int, int, int, const int*);

extern const int data_020e6aec[];
extern const int data_020e6b6c[];

static const double zero = 0.00000000000000000000e+00;
static const double half = 5.00000000000000000000e-01;
static const double two24 = 1.67772160000000000000e+07;
static const double invpio2 = 6.36619772367581382433e-01;
static const double pio2_1 = 1.57079632673412561417e+00;
static const double pio2_1t = 6.07710050650619224932e-11;
static const double pio2_2 = 6.07710050630396597660e-11;
static const double pio2_2t = 2.02226624879595063154e-21;
static const double pio2_3 = 2.02226624871116645580e-21;
static const double pio2_3t = 8.47842766036889956997e-32;

// USA: func_02007028
extern "C" ARM int func_02007028(double x, double* y) {
    double z, w, t, r, fn;
    double tx[3];
    int e0, i, j, var9, n, var11, var12;

    var12 = ((int*)&x)[1];
    var11 = var12 & 0x7fffffff;
    if (var11 <= 0x3fe921fb) {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (var11 < 0x4002d97c) {
        if (var12 > 0) {
            z = x - pio2_1;
            if (var11 != 0x3ff921fb) {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = x + pio2_1;
            if (var11 != 0x3ff921fb) {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            } else {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (var11 <= 0x413921fb) {
        t = func_02008f3c(x);
        n = (int)(t * invpio2 + half);
        fn = (double)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && var11 != data_020e6aec[n - 1]) {
            y[0] = r - w;
        } else {
            j = var11 >> 20;
            y[0] = r - w;
            i = j - ((((int*)y)[1] >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                i = j - ((((int*)y)[1] >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (var12 < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        } else {
            return n;
        }
    }
    if (var11 >= 0x7ff00000) {
        y[0] = y[1] = x - x;
        return 0;
    }
    ((int*)&z)[0] = ((int*)&x)[0];
    e0 = (var11 >> 20) - 1046;
    ((int*)&z)[1] = var11 - (e0 << 20);
    for (i = 0; i < 2; i++) {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * two24;
    }
    tx[2] = z;
    var9 = 3;
    while (tx[var9 - 1] == zero) {
        var9--;
    }
    n = func_02007a10(tx, y, e0, var9, 2, data_020e6b6c);
    if (var12 < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
