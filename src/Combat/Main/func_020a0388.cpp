#include <globaldefs.h>

struct Struct_020a0388 {
    char pad[0xc];
    unsigned int lo : 14;
    unsigned int val : 14;
    unsigned int hi : 4;
};

// USA: func_020a0388
extern "C" ARM void func_020a0388(struct Struct_020a0388* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x270f) {
        v = 0x270f;
    }
    p->val = v;
}
