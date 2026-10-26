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

// USA: func_02009edc
ARM void func_02009edc(Struct_020026b4* z, const Struct_020026b4* x, const Struct_020026b4* y) {
    int var0, var1;
    unsigned char *var2, *i, *var4;
    const unsigned char *var5, *j, *var7;

    *z = *x;

    if (y->sig.text[0] == 0)
        return;

    var0 = z->sig.length;
    if (var0 < y->sig.length)
        var0 = y->sig.length;

    var1 = z->unknown_2_ - y->unknown_2_;
    var0 += var1;

    if (var0 > 32)
        var0 = 32;

    while (z->sig.length < var0)
        z->sig.text[z->sig.length++] = 0;

    var2 = z->sig.text;
    i = var2 + var0;

    if (y->sig.length + var1 < var0)
        i = var2 + (y->sig.length + var1);

    var5 = y->sig.text;
    j = var5 + (i - var2 - var1);
    var7 = j;

    while (i > var2 && j > var5) {
        --i;
        --j;
        if (*i < *j) {
            unsigned char* k = i - 1;
            while (*k == 0)
                --k;
            while (k != i) {
                --*k;
                ++k;
                *k += 10;
            }
        }
        *i -= *j;
    }

    if (var7 - var5 < y->sig.length) {
        int var9 = 0;
        if (*var7 < 5)
            var9 = 1;
        else if (*var7 == 5) {
            const unsigned char* var10 = y->sig.text + y->sig.length;

            for (j = var7 + 1; j < var10; ++j)
                if (*j != 0)
                    goto done;

            i = var2 + (var7 - var5) + var1 - 1;

            if (*i & 1)
                var9 = 1;
        }
        if (var9) {
            if (*i < 1) {
                unsigned char* k = i - 1;
                while (*k == 0)
                    --k;
                while (k != i) {
                    --*k;
                    ++k;
                    *k += 10;
                }
            }
            *i -= 1;
        }
    }

done:
    for (i = var2; *i == 0; ++i) {
    }

    if (i > var2) {
        unsigned char var12 = (unsigned char)(i - var2);
        z->unknown_2_ -= var12;
        var4 = var2 + z->sig.length;
        for (; i < var4; ++i, ++var2)
            *var2 = *i;
        z->sig.length -= var12;
    }

    var2 = z->sig.text;
    for (i = var2 + z->sig.length; i > var2;) {
        --i;
        if (*i != 0)
            break;
    }
    z->sig.length = (unsigned char)(i - var2 + 1);
}
