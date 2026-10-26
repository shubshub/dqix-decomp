#include <globaldefs.h>

extern "C" int func_0200aa74(double x);
extern "C" double func_02008da4(double x, double y);

static const double two54 = 1.80143985094819840000e+16;
static const double twom54 = 5.55111512312578270212e-17;
static const double big = 1.0e+300;
static const double tiny = 1.0e-300;

// USA: func_020091d8
extern "C" ARM double func_020091d8(double x, int n) {
    int k, var1, var2;
    if (!(func_0200aa74(x) > 2) || x == 0.0) {
        return x;
    }

    var1 = ((int*)&x)[1];
    var2 = ((int*)&x)[0];
    k = (var1 & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((var2 | (var1 & 0x7fffffff)) == 0) {
            return x;
        }
        x *= two54;
        var1 = ((int*)&x)[1];
        k = ((var1 & 0x7ff00000) >> 20) - 54;
        if (n < -50000) {
            return tiny * x;
        }
    }
    if (k == 0x7ff) {
        return x + x;
    }
    k = k + n;
    if (k > 0x7fe) {
        return big * func_02008da4(big, x);
    }
    if (k > 0) {
        ((int*)&x)[1] = (var1 & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54) {
        if (n > 50000) {
            return big * func_02008da4(big, x);
        } else {
            return tiny * func_02008da4(tiny, x);
        }
    }
    k += 54;
    ((int*)&x)[1] = (var1 & 0x800fffff) | (k << 20);
    return x * twom54;
}
