#include <globaldefs.h>

struct Struct_020a0228 {
    char pad[0x18];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0228
extern "C" ARM void func_020a0228(struct Struct_020a0228* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
