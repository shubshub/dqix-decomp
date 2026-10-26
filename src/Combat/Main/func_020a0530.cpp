#include <globaldefs.h>

struct Struct_020a0530 {
    char pad[0x1c];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0530
extern "C" ARM void func_020a0530(struct Struct_020a0530* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
