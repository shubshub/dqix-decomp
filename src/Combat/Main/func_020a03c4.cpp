#include <globaldefs.h>

struct Struct_020a03c4 {
    char pad[0x10];
    unsigned int val : 9;
    unsigned int hi : 23;
};

// USA: func_020a03c4
extern "C" ARM void func_020a03c4(struct Struct_020a03c4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1f4) {
        v = 0x1f4;
    }
    p->val = v;
}
