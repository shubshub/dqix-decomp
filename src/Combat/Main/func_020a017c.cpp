#include <globaldefs.h>

struct Struct_020a017c {
    char pad[0x14];
    unsigned int lo : 10;
    unsigned int val : 10;
    unsigned int hi : 12;
};

// USA: func_020a017c
extern "C" ARM void func_020a017c(struct Struct_020a017c* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
