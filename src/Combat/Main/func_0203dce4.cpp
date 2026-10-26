#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"

struct Struct_0203dce4_2 {
    char pad[0xc];
    struct Struct_0203dce4* entries[0x20];
};

// USA: func_0203dce4
extern "C" ARM struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id) {
    struct Struct_0203dce4* entry;
    if ((unsigned int)id >= 0x20) {
        return 0;
    }
    entry = list->entries[id];
    if (entry != 0 && (entry->flags & 0x8000)) {
        entry = 0;
    }
    return entry;
}
