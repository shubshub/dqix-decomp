#include <globaldefs.h>

struct Struct_020be7a8 { int f0; int f4; int f8; };
struct Struct_020be7a8_2 {
    char pad[0x1c];
    unsigned int count;
    struct Struct_020be7a8 elems[1];
};

// USA: func_020c01ac
extern "C" ARM struct Struct_020be7a8 *func_020c01ac(struct Struct_020be7a8_2 *list, int index) {
    struct Struct_020be7a8 *e;
    if (index < 0) {
        return NULL;
    }
    if (index >= list->count) {
        return NULL;
    }
    e = &list->elems[index];
    if (e->f0 == -1) {
        return NULL;
    }
    return e;
}
