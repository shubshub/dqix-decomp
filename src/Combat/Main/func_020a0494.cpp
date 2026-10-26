#include <globaldefs.h>

struct Struct_0207cc18_3 {
    char pad[0x14];
    unsigned int lo : 9;
    unsigned int val : 9;
    unsigned int hi : 14;
};

// USA: func_020a0494
extern "C" ARM void func_020a0494(struct Struct_0207cc18_3* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1f4) {
        v = 0x1f4;
    }
    p->val = v;
}
