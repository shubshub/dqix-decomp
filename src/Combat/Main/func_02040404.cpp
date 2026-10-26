#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02040404 {
    char name[0x38];
    int flag;
};

struct Struct_0204027c_2 {
    unsigned int count;
    int unk4;
    struct Struct_02040404* entries;
};

// USA: func_02040404
extern "C" ARM int func_02040404(struct Struct_0204027c_2* container, const char* name) {
    unsigned int i;
    struct Struct_02040404* entries = container->entries;
    if (entries == NULL) {
        return -1;
    }
    for (i = 0; i < container->count; i++) {
        if (entries[i].flag < 0) {
            continue;
        }
        if (strcmp((char*)&entries[i], name) == 0) {
            return i;
        }
    }
    return -1;
}
