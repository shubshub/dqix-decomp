#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02040184 {
    char* name;
    char pad[0x10];
};
struct Struct_0203f0fc_2 {
    void* base;
    char pad[0x14];
    unsigned int count;
    Struct_02040184* entries;
};

// USA: func_02040184
extern "C" ARM int func_02040184(Struct_0203f0fc_2* table, const char* name) {
    unsigned int i;
    if (table->base == NULL)
        return -1;
    for (i = 0; i < table->count; i++) {
        if (strcmp(name, table->entries[i].name) == 0)
            return i;
    }
    return -1;
}
