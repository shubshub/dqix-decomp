#include <globaldefs.h>

struct Struct_020b0074 {
    unsigned short count;
    unsigned short flags;
    unsigned char *base;
};

// USA: func_020b0074
extern "C" ARM unsigned char *func_020b0074(struct Struct_020b0074 *h) {
    if (h->flags & 1) {
        return h->base + (h->count << 4);
    }
    return h->base + (h->count << 3);
}
