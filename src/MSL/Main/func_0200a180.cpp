#include <globaldefs.h>

struct Struct_020026b4 {
    unsigned char unknown_0_;
    char unused;
    short unknown_2_;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
};

extern "C" int func_0200aa60(double x);
extern "C" int func_0200aa74(double x);
extern "C" double func_0200911c(double x, int* arg1);
extern "C" double func_020091d8(double x, int n);
extern "C" unsigned char func_0200a9cc(unsigned long long v);
extern "C" void func_02009998(Struct_020026b4* d, long arg1);
extern "C" void func_020096ac(Struct_020026b4* result, unsigned long long val);
extern "C" void func_02009778(Struct_020026b4* result, const Struct_020026b4* x, const Struct_020026b4* y);

static inline int inline_0200a180(double x) {
    unsigned long long bits = *(unsigned long long*)&x | 0x0010000000000000ULL;
    return func_0200a9cc((bits & -bits) - 1);
}

// USA: func_0200a180
extern "C" ARM void func_0200a180(Struct_020026b4* d, double x) {
    char var0 = (char)(func_0200aa60(x) != 0);

    if (x == 0) {
        d->unknown_0_ = var0;
        d->unknown_2_ = 0;
        d->sig.length = 1;
        d->sig.text[0] = 0;
        return;
    }

    if (!(func_0200aa74(x) > 2)) {
        d->unknown_0_ = var0;
        d->unknown_2_ = 0;
        d->sig.length = 1;
        d->sig.text[0] = func_0200aa74(x) == 1 ? 'N' : 'I';
        return;
    }

    if (var0 != 0) {
        x = -x;
    }

    {
        int var1;
        double var2 = func_0200911c(x, &var1);
        int var3 = 53 - inline_0200a180(var2);
        Struct_020026b4 var4, var5;

        func_02009998(&var5, var1 - var3);
        func_020096ac(&var4, (unsigned long long)func_020091d8(var2, var3));
        func_02009778(d, &var4, &var5);
        d->unknown_0_ = var0;
    }
}
