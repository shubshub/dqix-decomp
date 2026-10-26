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

extern "C" void func_0200961c(Struct_020026b4* d, int digits);

// USA: func_02009778
extern "C" ARM void func_02009778(Struct_020026b4* result, const Struct_020026b4* x, const Struct_020026b4* y) {
    unsigned int accumulator = 0;
    unsigned char var1[32 * 2];
    int i = x->sig.length + y->sig.length - 1;
    unsigned char* var3 = var1 + i + 1;
    unsigned char* var4 = var3;

    result->unknown_0_ = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const unsigned char* var9;
        const unsigned char* var10;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        var9 = x->sig.text + j;
        var10 = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t) {
            l = t;
        }

        for (; l > 0; l--, var9++, var10--) {
            accumulator += *var9 * *var10;
        }

        *--var3 = (unsigned char)(accumulator % 10);
        accumulator /= 10;
    }

    result->unknown_2_ = (short)(x->unknown_2_ + y->unknown_2_);

    if (accumulator) {
        *--var3 = (unsigned char)(accumulator);
        result->unknown_2_++;
    }

    for (i = 0; i < 32 && var3 < var4; i++, var3++) {
        result->sig.text[i] = *var3;
    }
    result->sig.length = (unsigned char)(i);

    if (var3 < var4 && *var3 >= 5) {
        if (*var3 == 5) {
            unsigned char* var11 = var3 + 1;
            for (; var11 < var4; var11++) {
                if (*var11 != 0) {
                    goto round;
                }
            }
            if ((var3[-1] & 1) == 0) {
                return;
            }
        }
    round:
        func_0200961c(result, result->sig.length);
    }
}
