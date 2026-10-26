#include <globaldefs.h>

struct Struct_020bc158_2 { char pad[0x41]; unsigned char unknown_41_; };
struct Struct_020bc158 { struct Struct_020bc158_2 *f0; };

static inline bool inline_020bc158(const struct Struct_020bc158 *o) { return o->f0 != NULL; }

// USA: func_020bc158
extern "C" ARM void func_020bc158(struct Struct_020bc158 *p, unsigned char val) {
    if (inline_020bc158(p)) {
        p->f0->unknown_41_ = val;
    }
}
