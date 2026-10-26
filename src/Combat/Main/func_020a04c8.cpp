#include <globaldefs.h>

struct Struct_0206e424_4 {
    char pad[0x14];
    unsigned int lo : 18;
    unsigned int val : 11;
    unsigned int hi : 3;
};

// USA: func_020a04c8
extern "C" ARM void func_020a04c8(struct Struct_0206e424_4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x5dc) {
        v = 0x5dc;
    }
    p->val = v;
}
