#include <globaldefs.h>

struct Struct_02095ff0 {
    char pad[0x8];
    unsigned int lo : 24;
    unsigned int val : 8;
};

// USA: func_020a0364
extern "C" ARM void func_020a0364(struct Struct_02095ff0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xfa) {
        v = 0xfa;
    }
    p->val = v;
}
