#include <globaldefs.h>

#if defined(jpn)
#define func_020a0644 func_020a23bc
#endif

struct S_a0644 {
    char pad[0x24];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0644
extern "C" ARM void func_020a0644(struct S_a0644* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
