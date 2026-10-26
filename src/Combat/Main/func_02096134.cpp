#include <globaldefs.h>

struct Struct_0205faf4_8 { unsigned int id : 9; unsigned int hi : 23; char pad[0xc]; };
struct Struct_0205faf4_7 { unsigned char count; char pad[3]; struct Struct_0205faf4_8 elems[1]; };

// USA: func_02096134
extern "C" ARM struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7* t, int id) {
    int i;
    if (id > 0xcc || id < 0) return NULL;
    for (i = 0; i < t->count; i++) {
        if (t->elems[i].id == id) return &t->elems[i];
    }
    return NULL;
}
