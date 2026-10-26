#include <globaldefs.h>

struct Struct_02070b6c_4 {
    unsigned char data[0x84];
};

struct Struct_02070b6c_3 {
    unsigned int count : 12;
    struct Struct_02070b6c_4 *elements;
};

typedef int (*Type_02070e60)(struct Struct_02070b6c_4 *);

// USA: func_02070e60
extern "C" ARM struct Struct_02070b6c_4 *func_02070e60(struct Struct_02070b6c_3 *container, int key, Type_02070e60 arg2) {
    struct Struct_02070b6c_4 *elements = container->elements;
    int count;
    int lo, hi;
    if (elements == NULL || arg2 == NULL) return NULL;
    count = container->count;
    if (count == 0) return NULL;
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        int var4 = lo + ((hi - lo + 1) >> 1);
        struct Struct_02070b6c_4 *e = elements + var4;
        int r = arg2(e);
        if (r == key) return e;
        if (r > key) hi = var4 - 1;
        else lo = var4 + 1;
    }
    return NULL;
}
