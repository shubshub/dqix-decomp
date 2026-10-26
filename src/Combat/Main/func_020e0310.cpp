#include <globaldefs.h>

struct Struct_020e0028 {
    int a;
    int b;
};

struct Container020e0310 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Struct_020e0028 *base;
};

typedef int (*Type_020e0028)(struct Struct_020e0028 *);

// USA: func_020e0310
extern "C" ARM struct Struct_020e0028 *func_020e0310(struct Container020e0310 *c, int key, Type_020e0028 fn) {
    struct Struct_020e0028 *base;
    int count;
    int low;
    int high;
    int var4;
    struct Struct_020e0028 *elem;
    int result;

    base = c->base;
    if (base == NULL || fn == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    high = count - 1;
    low = 0;
    while (low <= high) {
        var4 = low + ((high - low + 1) >> 1);
        elem = base + var4;
        result = fn(elem);
        if (result == key) return elem;
        if (result > key) high = var4 - 1;
        else low = var4 + 1;
    }
    return NULL;
}
