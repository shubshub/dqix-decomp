#include <globaldefs.h>

struct Struct_0204a5d4 {
    char pad[0x260];
    int unknown_260_;
};

// USA: func_0204a5d4
extern "C" ARM void func_0204a5d4(struct Struct_0204a5d4* p, int v) {
    p->unknown_260_ = v;
}
