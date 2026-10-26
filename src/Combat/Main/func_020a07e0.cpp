#include <globaldefs.h>

struct Struct_020a07e0 {
    char pad[0x3c];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a07e0
extern "C" ARM void func_020a07e0(struct Struct_020a07e0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
