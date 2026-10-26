#include <globaldefs.h>

struct Struct_020a00d4 {
    char pad[0x10];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a00d4
extern "C" ARM void func_020a00d4(struct Struct_020a00d4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
