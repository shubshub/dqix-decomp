#include <globaldefs.h>

struct Struct_020725d8_2 {
    signed short id;
    char unk[0x2a];
};

struct Struct_020725d8 {
    struct Struct_020725d8_2* entries;
    short count;
};

// USA: func_020725d8
extern "C" ARM struct Struct_020725d8_2* func_020725d8(struct Struct_020725d8* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return &list->entries[i];
        }
    }
    return 0;
}
