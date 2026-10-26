#include <globaldefs.h>

struct Struct_020a00a4 {
    char pad[0xc];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a00a4
extern "C" ARM void func_020a00a4(struct Struct_020a00a4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
