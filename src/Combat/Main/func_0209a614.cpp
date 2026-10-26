#include <globaldefs.h>

struct Struct_0209a614_2 {
    unsigned short field0;
    unsigned short id;
    char pad[8];
};
struct Struct_0209a614 {
    struct Struct_0209a614_2* entries;
    int count;
};

// USA: func_0209a614
extern "C" ARM struct Struct_0209a614_2* func_0209a614(struct Struct_0209a614* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return &list->entries[i];
        }
    }
    return NULL;
}
