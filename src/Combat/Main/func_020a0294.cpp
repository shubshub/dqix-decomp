#include <globaldefs.h>

struct Struct_020a0294 {
    char pad[0x1c];
    unsigned int lo : 10;
    unsigned int val : 16;
    unsigned int hi : 6;
};

// USA: func_020a0294
extern "C" ARM void func_020a0294(struct Struct_020a0294* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
