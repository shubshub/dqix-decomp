#include <globaldefs.h>

struct Struct_020e5750 {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};

struct Struct_020e5750_2 {
    struct Struct_020e5750* base;
    int capacity;
    int count;
};

// USA: func_020e587c
extern "C" ARM void func_020e587c(struct Struct_020e5750_2* list, struct Struct_020e5750* entry) {
    struct Struct_020e5750* dst;
    if (entry == NULL) {
        return;
    }
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->base[list->count];
    dst->field0 = entry->field0;
    dst->field4 = entry->field4;
    dst->lo = entry->lo;
    dst->hi = entry->hi;
    dst->field10 = entry->field10;
    list->count++;
}
