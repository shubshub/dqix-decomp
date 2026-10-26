#include <globaldefs.h>

struct Struct_0209a654 {
    char pad[12];
};
struct Struct_0209a654_2 {
    struct Struct_0209a654* entries;
    int count;
};

// USA: func_0209a654
extern "C" ARM struct Struct_0209a654* func_0209a654(struct Struct_0209a654_2* list, unsigned int index) {
    if (list->count <= index) {
        return NULL;
    }
    return &list->entries[index];
}
