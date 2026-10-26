#include <globaldefs.h>

typedef struct Struct_020026b4 {
    char unknown_0_;
    char unused;
    short unknown_2_;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} Struct_020026b4;

typedef struct Struct_020026b4_2 {
    char style;
    char unused;
    short digits;
} Struct_020026b4_2;

extern "C" void func_0200a180(Struct_020026b4* d, double x);
extern "C" void func_0200966c(Struct_020026b4* d, int digits);

// USA: func_0200a300
extern "C" ARM void func_0200a300(const Struct_020026b4_2* f, double x, Struct_020026b4* d) {
    short digits = f->digits;
    int i;

    func_0200a180(d, x);

    if (d->sig.text[0] > 9)
        return;

    if (digits > 32)
        digits = 32;

    func_0200966c(d, digits);

    while (d->sig.length < digits)
        d->sig.text[d->sig.length++] = 0;

    d->unknown_2_ -= d->sig.length - 1;

    for (i = 0; i < d->sig.length; i++)
        d->sig.text[i] += '0';
}
