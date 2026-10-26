#include <globaldefs.h>

struct Struct_0204a5dc {
    char pad[0x220];
    int unknown_220_;
};

// USA: func_0204a5dc
extern "C" ARM void func_0204a5dc(struct Struct_0204a5dc* p, int v) {
    p->unknown_220_ = v;
}
