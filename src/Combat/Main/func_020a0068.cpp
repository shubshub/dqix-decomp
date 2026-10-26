#include <globaldefs.h>

struct Struct_020a0068 {
    char pad[0xc];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0068
extern "C" ARM void func_020a0068(struct Struct_020a0068* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
