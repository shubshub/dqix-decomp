#include <globaldefs.h>

struct Struct_020a83b0_2 {
    unsigned char field0;
    unsigned char id;
    unsigned char pad[0x2a];
};

struct Struct_020a83b0 {
    struct Struct_020a83b0_2 *entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_020a83b0
extern "C" ARM struct Struct_020a83b0_2* func_020a83b0(struct Struct_020a83b0 *list, int id) {
    int i;
    if (id < 0) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        struct Struct_020a83b0_2 *entry = &list->entries[i];
        if (id == entry->id) {
            return entry;
        }
    }
    return 0;
}
