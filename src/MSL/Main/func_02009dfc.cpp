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

// USA: func_02009dfc
extern "C" ARM int func_02009dfc(const Struct_020026b4* x, const Struct_020026b4* y) {
    if (x->sig.text[0] == 0) {
        if (y->sig.text[0] != 0)
            return 1;
        return 0;
    }
    if (y->sig.text[0] == 0)
        return 0;

    if (x->unknown_2_ == y->unknown_2_) {
        int i;
        int l = x->sig.length;

        if (l > y->sig.length)
            l = y->sig.length;

        for (i = 0; i < l; i++) {
            if (x->sig.text[i] < y->sig.text[i])
                return 1;
            if (y->sig.text[i] < x->sig.text[i])
                return 0;
        }

        if (l == x->sig.length) {
            for (; i < y->sig.length; i++) {
                if (y->sig.text[i] != 0)
                    return 1;
            }
        }
        return 0;
    }
    return x->unknown_2_ < y->unknown_2_;
}
