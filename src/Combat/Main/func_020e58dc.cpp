#include <globaldefs.h>

struct Struct_020e58dc_2 {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};

struct Struct_020e58dc {
    struct Struct_020e58dc_2* base;
    int field4;
    int count;
};

// USA: func_020e58dc
extern "C" ARM struct Struct_020e58dc_2* func_020e58dc(struct Struct_020e58dc* list, int key) {
    struct Struct_020e58dc_2* entry = list->base;
    int i;
    for (i = 0; i < list->count; i++) {
        if (entry->lo <= key && key < entry->hi) {
            return entry;
        }
        entry++;
    }
    return NULL;
}
