#include <globaldefs.h>

extern "C" double _dmul(double a, double b);

// USA: func_0200911c
extern "C" ARM double func_0200911c(double value, int* arg1, int pad) {
    int hi = ((int*)&value)[1];
    int lo = ((int*)&value)[0];
    int var2 = hi & 0x7fffffff;
    *arg1 = 0;

    if (var2 >= 0x7ff00000 || (var2 | lo) == 0) {
        return value;
    }

    if (var2 < 0x100000) {
        value = _dmul(value, 18014398509481984.0);
        *arg1 = -0x36;
        hi = ((int*)&value)[1];
        var2 = hi & 0x7fffffff;
    }

    *arg1 += -0x3fe + (var2 >> 20);
    ((int*)&value)[1] = (hi & 0x800fffff) | 0x3fe00000;
    return value;
}
