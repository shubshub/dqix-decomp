#include <globaldefs.h>

struct Struct_0202811c {
    unsigned short a;
    unsigned short b;
};

struct Struct_02028104 {
    char pad[0x20];
    int result;
    char pad2[1];
    unsigned char count;
    char pad3[2];
    struct Struct_0202811c* entries;
};

// USA: func_0202811c
extern "C" ARM void func_0202811c(struct Struct_02028104* s) {
    int i;
    struct Struct_0202811c* entries;
    s->result = 1;
    entries = s->entries;
    if (entries == NULL) return;
    for (i = 0; i < s->count; i++) {
        struct Struct_0202811c* e = &entries[i];
        if (e->a != e->b) {
            s->result = 0;
            return;
        }
    }
}
