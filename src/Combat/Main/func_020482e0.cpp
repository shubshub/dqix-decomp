#include <globaldefs.h>

struct Struct_020482e0_2 {
    unsigned int flags;
    unsigned short count;
};

struct Struct_020482e0 {
    char pad[0x130];
    struct Struct_020482e0_2* sub;
};

// USA: func_020482e0
extern "C" ARM int func_020482e0(struct Struct_020482e0* c, int amount, int force) {
    struct Struct_020482e0_2* sub = c->sub;
    unsigned short count = sub->count;
    if (count <= amount) {
        if (force == 0) {
            sub->count = 1;
            return count - 1;
        }
        sub->count = 0;
        int var2 = 0;
        if (c->sub->flags & 4) {
            var2 = 1;
        }
        c->sub->flags = 1;
        if (var2) {
            c->sub->flags |= 4;
        }
        return count;
    }
    sub->count = count - amount;
    return amount;
}
