#include <globaldefs.h>

struct Struct_02076cc4 {
    char pad[0x16c];
    int unknown_16c_;
};

// USA: func_02076cc4
extern "C" ARM void func_02076cc4(struct Struct_02076cc4* p, int v) {
    p->unknown_16c_ = v;
}
