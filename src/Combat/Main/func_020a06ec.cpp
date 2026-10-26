#include <globaldefs.h>

struct Struct_020a06ec {
    char pad[0x28];
    unsigned int lo : 22;
    unsigned int val : 10;
};

// USA: func_020a06ec
extern "C" ARM void func_020a06ec(struct Struct_020a06ec* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
