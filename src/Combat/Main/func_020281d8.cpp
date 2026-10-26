#include <globaldefs.h>

struct Struct_0201a300 {
    int a;
    int b;
};

struct Struct_0201a300_12 {
    unsigned char b0;
    unsigned char capacity;
    unsigned char b2;
    unsigned char count;
    int w4;
    struct Struct_0201a300* entries;
};

// USA: func_020281d8
extern "C" ARM void func_020281d8(struct Struct_0201a300_12* list, struct Struct_0201a300* src) {
    struct Struct_0201a300* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
