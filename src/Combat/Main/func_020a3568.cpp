#include <globaldefs.h>

struct Struct_020a3568 {
    char pad[0x218];
    int unknown_218_;
};

// USA: func_020a3568
extern "C" ARM void func_020a3568(struct Struct_020a3568* p, int v) {
    p->unknown_218_ = v;
}
