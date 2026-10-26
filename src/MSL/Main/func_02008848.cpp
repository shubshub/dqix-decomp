#include <globaldefs.h>

extern "C" double func_02008f3c(double x);

static const double data_020e6cc4[] = {
    2.26987774529616870924e-17,
    3.06161699786838301793e-17,
    1.39033110312309984516e-17,
    6.12323399573676603587e-17,
};

static const double data_020e6ce4[] = {
    4.63647609000806093515e-01,
    7.85398163397448278999e-01,
    9.82793723247329054082e-01,
    1.57079632679489655800e+00,
};

extern const double data_020e6d04[];

// USA: func_02008848
extern "C" ARM double func_02008848(double x) {
    double w, s1, s2, z;
    int var4, var5, id;

    var5 = ((int*)&x)[1];
    var4 = var5 & 0x7fffffff;
    if (var4 >= 0x44100000) {
        if (var4 > 0x7ff00000 || (var4 == 0x7ff00000 && (((int*)&x)[0] != 0)))
            return x + x;
        if (var5 > 0)
            return data_020e6ce4[3] + data_020e6cc4[3];
        else
            return -data_020e6ce4[3] - data_020e6cc4[3];
    }
    if (var4 < 0x3fdc0000) {
        if (var4 < 0x3e200000) {
            if (1.0e300 + x > 1.0)
                return x;
        }
        id = -1;
    } else {
        x = func_02008f3c(x);
        if (var4 < 0x3ff30000) {
            if (var4 < 0x3fe60000) {
                id = 0;
                x = (2.0 * x - 1.0) / (2.0 + x);
            } else {
                id = 1;
                x = (x - 1.0) / (x + 1.0);
            }
        } else {
            if (var4 < 0x40038000) {
                id = 2;
                x = (x - 1.5) / (1.0 + 1.5 * x);
            } else {
                id = 3;
                x = -1.0 / x;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (data_020e6d04[0] + w * (data_020e6d04[2] + w * (data_020e6d04[4] + w * (data_020e6d04[6] + w * (data_020e6d04[8] + w * data_020e6d04[10])))));
    s2 = w * (data_020e6d04[1] + w * (data_020e6d04[3] + w * (data_020e6d04[5] + w * (data_020e6d04[7] + w * data_020e6d04[9]))));
    if (id < 0)
        return x - x * (s1 + s2);
    else {
        z = data_020e6ce4[id] - ((x * (s1 + s2) - data_020e6cc4[id]) - x);
        return (var5 < 0) ? -z : z;
    }
}
