#include <globaldefs.h>

struct Struct_0207f0ac_2 {
    char pad[8];
    short id;
    char pad2[0x18 - 0xa];
};

struct Struct_0207f0ac {
    struct Struct_0207f0ac_2* entries;
    short count;
};

static inline struct Struct_0207f0ac_2* inline_0207f0ac(struct Struct_0207f0ac* list, unsigned int index) {
    return &list->entries[index];
}

// USA: func_0207f0ac
extern "C" ARM struct Struct_0207f0ac_2* func_0207f0ac(struct Struct_0207f0ac* list, int id) {
    short i;
    struct Struct_0207f0ac_2* e;
    if (id < 0) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        e = inline_0207f0ac(list, i);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
