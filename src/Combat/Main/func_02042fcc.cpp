#include <globaldefs.h>

struct Struct_02042c68 {
    short a0;
    short a2;
    short a4;
    short a6;
    int a8;
    int ac;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

// USA: func_02042fcc
extern "C" ARM void func_02042fcc(struct Struct_02042c68* p) {
    p->a6 = 0;
    p->a4 = 0;
    p->a2 = 0;
    p->a0 = 0;
    p->a8 = 0;
    p->ac = 0;
    p->unknown_14_ = 0;
    p->unknown_10_ = 0;
    p->unknown_18_ = 0x7fff;
}
