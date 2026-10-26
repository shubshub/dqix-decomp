#include <globaldefs.h>

struct Struct_0201a300_2 {
    unsigned short a;
    unsigned short b;
};

struct Struct_0201a300_9 {
    char pad[0x24];
    unsigned char capacity;
    unsigned char count;
    char pad2[2];
    struct Struct_0201a300_2* entries;
};

// USA: func_02028378
extern "C" ARM void func_02028378(struct Struct_0201a300_9* list, struct Struct_0201a300_2* src) {
    struct Struct_0201a300_2* entries = list->entries;
    struct Struct_0201a300_2* dst;
    if (entries == 0) {
        return;
    }
    if (list->capacity <= list->count) {
        return;
    }
    dst = &entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
