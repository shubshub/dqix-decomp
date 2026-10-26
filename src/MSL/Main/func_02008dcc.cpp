#include <globaldefs.h>

extern "C" double func_020085cc(double x, double y, int arg2);
extern "C" int func_02007028(double x, double* y);
extern "C" double func_020076f0(double x, double y);

// USA: func_02008dcc
extern "C" ARM double func_02008dcc(double x) {
    double y[2];
    double z = 0.0;
    int n;
    int var3;

    var3 = ((int*)&x)[1];

    var3 &= 0x7fffffff;
    if (var3 <= 0x3fe921fb) {
        return func_020076f0(x, z);
    } else if (var3 >= 0x7ff00000) {
        return x - x;
    } else {
        n = func_02007028(x, y);
        switch (n & 3) {
        case 0:
            return func_020076f0(y[0], y[1]);
        case 1:
            return -func_020085cc(y[0], y[1], 1);
        case 2:
            return -func_020076f0(y[0], y[1]);
        default:
            return func_020085cc(y[0], y[1], 1);
        }
    }
}
