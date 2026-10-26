#include <globaldefs.h>

static const double
half = 5.00000000000000000000e-01,
S1 = -1.66666666666666324348e-01,
S2 = 8.33333333332248946124e-03,
S3 = -1.98412698298579493134e-04,
S4 = 2.75573137070700676789e-06,
S5 = -2.50507602534068634195e-08,
S6 = 1.58969099521155010221e-10;

// USA: func_020085cc
extern "C" ARM double func_020085cc(double x, double y, int arg2) {
    double z, r, v;
    int var3;

    var3 = ((int*)&x)[1] & 0x7fffffff;
    if (var3 < 0x3e400000) {
        if ((int)x == 0) return x;
    }
    z = x * x;
    v = z * x;
    r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
    if (arg2 == 0) return x + v * (S1 + z * r);
    else return x - ((z * (half * y - v * r) - y) - v * S1);
}
