#include <globaldefs.h>

struct Struct_020a0608 {
    char pad[0x24];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0608
extern "C" ARM void func_020a0608(struct Struct_020a0608* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
