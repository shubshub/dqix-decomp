#include <globaldefs.h>

extern "C" ARM double func_0200aae4(double x, int n);
extern "C" ARM double func_02008f5c(double x);

extern const int data_020e6c74[];
extern const double data_020e6c84[];

static const double
zero   = 0.0,
one    = 1.0,
two24  = 1.67772160000000000000e+07,
twon24 = 5.96046447753906250000e-08;

// USA: func_02007a10
extern "C" ARM int func_02007a10(double* x, double* y, int e0, int arg3, int arg4, const int* arg5) {
    int var0, var1, var2, var3, var4, var5, n, var7[20], i, j, k, m, var12, var13;
    double z, fw, f[20], var17[20], q[20];

    var4 = data_020e6c74[arg4];
    var3 = var4;

    var1 = arg3 - 1;
    var2 = (e0 - 3) / 24; if (var2 < 0) var2 = 0;
    var12 = e0 - 24 * (var2 + 1);

    j = var2 - var1; m = var1 + var4;
    for (i = 0; i <= m; i++, j++) f[i] = (j < 0) ? zero : (double)arg5[j];

    for (i = 0; i <= var4; i++) {
        for (j = 0, fw = 0.0; j <= var1; j++) fw += x[j] * f[var1 + i - j];
        q[i] = fw;
    }

    var0 = var4;
recompute:
    for (i = 0, j = var0, z = q[var0]; j > 0; i++, j--) {
        fw    = (double)((int)(twon24 * z));
        var7[i] = (int)(z - two24 * fw);
        z     = q[j - 1] + fw;
    }

    z  = func_0200aae4(z, var12);
    z -= 8.0 * func_02008f5c(z * 0.125);
    n  = (int)z;
    z -= (double)n;
    var13 = 0;
    if (var12 > 0) {
        i  = (var7[var0 - 1] >> (24 - var12)); n += i;
        var7[var0 - 1] -= i << (24 - var12);
        var13 = var7[var0 - 1] >> (23 - var12);
    }
    else if (var12 == 0) var13 = var7[var0 - 1] >> 23;
    else if (z >= 0.5) var13 = 2;

    if (var13 > 0) {
        n += 1; var5 = 0;
        for (i = 0; i < var0; i++) {
            j = var7[i];
            if (var5 == 0) {
                if (j != 0) {
                    var5 = 1; var7[i] = 0x1000000 - j;
                }
            } else var7[i] = 0xffffff - j;
        }
        if (var12 > 0) {
            switch (var12) {
            case 1:
                var7[var0 - 1] &= 0x7fffff; break;
            case 2:
                var7[var0 - 1] &= 0x3fffff; break;
            }
        }
        if (var13 == 2) {
            z = one - z;
            if (var5 != 0) z -= func_0200aae4(one, var12);
        }
    }

    if (z == zero) {
        j = 0;
        for (i = var0 - 1; i >= var4; i--) j |= var7[i];
        if (j == 0) {
            for (k = 1; var7[var4 - k] == 0; k++);

            for (i = var0 + 1; i <= var0 + k; i++) {
                f[var1 + i] = (double)arg5[var2 + i];
                for (j = 0, fw = 0.0; j <= var1; j++) fw += x[j] * f[var1 + i - j];
                q[i] = fw;
            }
            var0 += k;
            goto recompute;
        }
    }

    if (z == 0.0) {
        var0 -= 1; var12 -= 24;
        while (var7[var0] == 0) { var0--; var12 -= 24; }
    } else {
        z = func_0200aae4(z, -var12);
        if (z >= two24) {
            fw = (double)((int)(twon24 * z));
            var7[var0] = (int)(z - two24 * fw);
            var0 += 1; var12 += 24;
            var7[var0] = (int)fw;
        } else var7[var0] = (int)z;
    }

    fw = func_0200aae4(one, var12);
    for (i = var0; i >= 0; i--) {
        q[i] = fw * (double)var7[i]; fw *= twon24;
    }

    for (i = var0; i >= 0; i--) {
        for (fw = 0.0, k = 0; k <= var3 && k <= var0 - i; k++) fw += data_020e6c84[k] * q[i + k];
        var17[var0 - i] = fw;
    }

    switch (arg4) {
    case 0:
        fw = 0.0;
        for (i = var0; i >= 0; i--) fw += var17[i];
        y[0] = (var13 == 0) ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0;
        for (i = var0; i >= 0; i--) fw += var17[i];
        y[0] = (var13 == 0) ? fw : -fw;
        fw = var17[0] - fw;
        for (i = 1; i <= var0; i++) fw += var17[i];
        y[1] = (var13 == 0) ? fw : -fw;
        break;
    case 3:
        for (i = var0; i > 0; i--) {
            fw      = var17[i - 1] + var17[i];
            var17[i]  += var17[i - 1] - fw;
            var17[i - 1] = fw;
        }
        for (i = var0; i > 1; i--) {
            fw      = var17[i - 1] + var17[i];
            var17[i]  += var17[i - 1] - fw;
            var17[i - 1] = fw;
        }
        for (fw = 0.0, i = var0; i >= 2; i--) fw += var17[i];
        if (var13 == 0) {
            y[0] = var17[0]; y[1] = var17[1]; y[2] = fw;
        } else {
            y[0] = -var17[0]; y[1] = -var17[1]; y[2] = -fw;
        }
    }
    return n & 7;
}
