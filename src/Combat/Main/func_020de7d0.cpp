#include <globaldefs.h>

struct Struct_020de7d0 {
    unsigned int v[8];
};

struct Struct_020de714 {
    unsigned short count;
    unsigned char pad[10];
    struct Struct_020de7d0* base;
};

typedef void (*Type_020de714)(struct Struct_020de714*, struct Struct_020de7d0*);

// USA: func_020de7d0
extern "C" ARM int func_020de7d0(struct Struct_020de714* c, Type_020de714 cb) {
    int count;
    struct Struct_020de7d0* elem;
    int i;

    elem = c->base;
    if (elem == NULL || (count = c->count) == 0 || cb == NULL) return 0;
    for (i = 0; i < count; i++, elem++) {
        cb(c, elem);
    }
    return 1;
}
