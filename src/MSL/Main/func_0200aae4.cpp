#include <globaldefs.h>

extern "C" double func_0200911c(double val, int* arg1);
extern "C" double func_020091d8(double val, int arg1);

// USA: func_0200aae4
extern "C" ARM double func_0200aae4(double val, int c) {
    int var0;
    double t = func_0200911c(val, &var0);
    var0 = var0 + c;
    return func_020091d8(t, var0);
}
