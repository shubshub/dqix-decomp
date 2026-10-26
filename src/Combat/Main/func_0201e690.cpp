#include <globaldefs.h>

struct Struct_0201e690 {
    unsigned short id;
    char unk[0x72];
};

struct Struct_0201afd0_4 {
    char unk[0x24];
    struct Struct_0201e690* entries;
    int count;
};

// USA: func_0201e690
extern "C" ARM struct Struct_0201e690* func_0201e690(struct Struct_0201afd0_4* list, int id) {
    struct Struct_0201e690* entry;
    int i;
    if (id < 0) {
        return 0;
    }
    entry = list->entries;
    for (i = 0; i < list->count; i++, entry++) {
        if (entry->id == id) {
            return entry;
        }
    }
    return 0;
}
