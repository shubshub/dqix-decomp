#include <globaldefs.h>

struct Struct_0207f6ac {
    char pad[4];
    short id;
    char pad2[0x30 - 0x6];
};

struct Struct_0207f524 {
    struct Struct_0207f6ac* entries;
    short count;
};

static inline struct Struct_0207f6ac* inline_0207f6ac(struct Struct_0207f524* list, unsigned int index) {
    return &list->entries[index];
}

// USA: func_0207f6ac
extern "C" ARM struct Struct_0207f6ac* func_0207f6ac(struct Struct_0207f524* list, int id) {
    short i;
    struct Struct_0207f6ac* e;
    if (id < 0) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        e = inline_0207f6ac(list, i);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
