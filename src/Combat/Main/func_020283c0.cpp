#include <globaldefs.h>

struct Struct_020283c0 {
    unsigned char id;
    unsigned char unk[0xF];
};

struct Struct_0201a300_11 {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unknown_3_;
    struct Struct_020283c0* entries;
};

// USA: func_020283c0
extern "C" ARM struct Struct_020283c0* func_020283c0(struct Struct_0201a300_11* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Struct_020283c0* entries = list->entries;
        if (id == entries[i].id) {
            return &entries[i];
        }
    }
    return NULL;
}
