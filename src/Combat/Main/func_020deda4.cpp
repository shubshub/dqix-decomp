#include <globaldefs.h>

extern "C" int func_020ded1c(int, int, int, int);

struct Fields020deda4 {
    unsigned char pad0[0x10];
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int rest : 12;
};

// USA: func_020deda4
extern "C" ARM int func_020deda4(int a, int b, struct Fields020deda4* c) {
    if (c != NULL) {
        return func_020ded1c(a, b, c->unknown_10_0_, c->unknown_11_2_);
    }
    return 0;
}
