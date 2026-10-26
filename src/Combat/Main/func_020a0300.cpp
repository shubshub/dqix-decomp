#include <globaldefs.h>

struct Struct_020a0300 {
    char pad[0x24];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a0300
extern "C" ARM void func_020a0300(struct Struct_020a0300* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
