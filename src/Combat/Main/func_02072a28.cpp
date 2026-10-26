#include <globaldefs.h>

struct Struct_0207267c {
    short a;
    int b;
};

struct Struct_02072a28 {
    struct Struct_0207267c* entries;
    short capacity;
    short count;
};

// USA: func_02072a28
extern "C" ARM void func_02072a28(struct Struct_02072a28* list, struct Struct_0207267c* src) {
    struct Struct_0207267c* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
