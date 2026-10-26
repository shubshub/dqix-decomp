#include <globaldefs.h>

struct Struct_020a0330 {
    char pad[0x8];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a0330
extern "C" ARM void func_020a0330(struct Struct_020a0330* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1869f) {
        v = 0x1869f;
    }
    p->val = v;
}
