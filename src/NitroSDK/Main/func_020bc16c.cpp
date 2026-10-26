#include <globaldefs.h>

struct Struct_020bc16c { char pad[0x40]; unsigned char f40; };
struct Struct_020bc16c_2 { struct Struct_020bc16c *f0; };

static inline bool inline_020bc158(const struct Struct_020bc16c_2 *o) { return o->f0 != NULL; }

// USA: func_020bc16c
extern "C" ARM void func_020bc16c(struct Struct_020bc16c_2 *p, unsigned char val) {
    if (inline_020bc158(p)) {
        p->f0->f40 = val;
    }
}
