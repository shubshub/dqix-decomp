#include <globaldefs.h>

struct Struct_020a02d0 {
    char pad[0x20];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a02d0
extern "C" ARM void func_020a02d0(struct Struct_020a02d0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
