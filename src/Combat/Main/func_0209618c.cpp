#include <globaldefs.h>

struct Struct_0205faf4_8;
struct Struct_0205faf4_7;
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7* t, int id);

struct Struct_0209618c {
    unsigned int pad0 : 11;
    unsigned int field : 3;
    unsigned int pad1 : 18;
};

// USA: func_0209618c
extern "C" ARM unsigned char func_0209618c(struct Struct_0205faf4_7* t, int id) {
    struct Struct_0205faf4_8* e = func_02096134(t, id);
    if (e != NULL) {
        return ((struct Struct_0209618c*)e)->field;
    }
    return 0;
}
