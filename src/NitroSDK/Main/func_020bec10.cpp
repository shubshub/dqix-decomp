#include <globaldefs.h>

struct Struct_020bec10_2 {
    unsigned int pad[68];
    unsigned int flags;
};

struct Struct_020bec10 {
    struct Struct_020bec10_2* inner;
};

static inline bool inline_020bc158(const struct Struct_020bec10* o) { return o->inner != NULL; }

// USA: func_020bec10
extern "C" ARM void func_020bec10(struct Struct_020bec10* owner) {
    if (inline_020bc158(owner)) {
        owner->inner->flags |= 4;
    }
}
