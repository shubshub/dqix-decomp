#include <globaldefs.h>

struct Struct_020dfa68 {
    int a;
    int b;
};

struct Struct_020df850 {
    unsigned short count;
    unsigned short pad2;
    int pad4;
    struct Struct_020dfa68 *elements;
};

typedef int (*Type_020df850)(struct Struct_020df850 *, struct Struct_020dfa68 *);

// USA: func_020dfa68
extern "C" ARM int func_020dfa68(struct Struct_020df850 *self, Type_020df850 cb) {
    int count;
    struct Struct_020dfa68 *elem;
    int i;

    elem = self->elements;
    if (elem == NULL || (count = self->count) == 0 || cb == NULL) return 0;
    for (i = 0; i < count; i++, elem++) {
        cb(self, elem);
    }
    return 1;
}
