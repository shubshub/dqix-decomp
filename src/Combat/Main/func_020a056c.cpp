#include <globaldefs.h>

struct Struct_020a056c {
    char pad[0x1c];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a056c
extern "C" ARM void func_020a056c(struct Struct_020a056c* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
