#include <globaldefs.h>

struct Struct_0202ea20 {
    char pad0[0x168];
    unsigned int unknown_168_;
    char pad1[0x78];
    int unknown_1e4_;
    int unknown_1e8_;
};

// USA: func_0202ea20
extern "C" ARM void func_0202ea20(struct Struct_0202ea20* p) {
    p->unknown_1e4_ = 0;
    p->unknown_1e8_ = 0;
    p->unknown_168_ &= ~0x4;
}
