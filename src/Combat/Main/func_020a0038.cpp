#include <globaldefs.h>

struct Struct_020a0038 {
    char pad[0x8];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0038
extern "C" ARM void func_020a0038(struct Struct_020a0038* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
