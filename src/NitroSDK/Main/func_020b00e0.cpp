#include <globaldefs.h>

struct Struct_0205a658_2 {
    unsigned short count;
    unsigned short flags;
    unsigned char *base;
};

// USA: func_020b00e0
extern "C" ARM unsigned char *func_020b00e0(struct Struct_0205a658_2 *h, unsigned int i) {
    if (i >= h->count) {
        return NULL;
    }
    if (h->flags & 1) {
        return h->base + (i << 4);
    }
    return h->base + (i << 3);
}
