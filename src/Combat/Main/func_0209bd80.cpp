#include <globaldefs.h>

struct Struct_0209bd80 { char pad[0x20]; };
struct Struct_02073ec4 { struct Struct_0209bd80 elems[6]; int count; };

// USA: func_0209bd80
extern "C" ARM struct Struct_0209bd80* func_0209bd80(struct Struct_02073ec4 *c, int index) {
    if (c->count <= index) return NULL;
    return &c->elems[index];
}
