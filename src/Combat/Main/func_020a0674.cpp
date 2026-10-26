#include <globaldefs.h>

struct Struct_020a0674 {
    char pad[0x28];
    unsigned int val : 12;
    unsigned int hi : 20;
};

// USA: func_020a0674
extern "C" ARM void func_020a0674(struct Struct_020a0674* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xfff) {
        v = 0xfff;
    }
    p->val = v;
}
