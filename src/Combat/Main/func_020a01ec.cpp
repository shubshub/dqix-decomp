#include <globaldefs.h>

struct Struct_020a01ec {
    char pad[0x18];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a01ec
extern "C" ARM void func_020a01ec(struct Struct_020a01ec* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
