#include <globaldefs.h>

struct Struct_020a0504 {
    char pad[0x18];
    unsigned int lo : 9;
    unsigned int val : 7;
    unsigned int hi : 16;
};

// USA: func_020a0504
extern "C" ARM void func_020a0504(struct Struct_020a0504* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 100) {
        v = 100;
    }
    p->val = v;
}
