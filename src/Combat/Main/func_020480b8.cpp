#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0204792c_3 {
    int count;
    char* entries;
};

// USA: func_020480b8
extern "C" ARM int func_020480b8(struct Struct_0204792c_3* table, char* key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (strcmp(key, table->entries + i * 30) == 0) return i;
    }
    return 0;
}
