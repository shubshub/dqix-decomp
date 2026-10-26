#include <globaldefs.h>

struct Struct_0207f524;

struct Struct_0207f7cc {
    char pad[0x2a];
    unsigned char flags;
};

extern "C" struct Struct_0207f7cc* func_0207f6ac(struct Struct_0207f524* list, int id);

// USA: func_0207f7cc
extern "C" ARM void func_0207f7cc(struct Struct_0207f524* list, int id, int mask) {
    struct Struct_0207f7cc* e = func_0207f6ac(list, id);
    if (e != NULL) {
        e->flags &= ~mask;
    }
}
