#include <globaldefs.h>

struct Struct_020b005c { unsigned int w[4]; };
struct Struct_0205a984_2 {
    unsigned short count;
    unsigned short pad;
    struct Struct_020b005c *entries;
};

// USA: func_020b005c
extern "C" ARM struct Struct_020b005c *func_020b005c(struct Struct_0205a984_2 *t, unsigned int i) {
    if (t->count > i) {
        return &t->entries[i];
    }
    return NULL;
}
