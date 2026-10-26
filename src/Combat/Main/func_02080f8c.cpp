#include <globaldefs.h>

struct Struct_02080f8c_2 { int value; };
struct Struct_0207f524 { struct Struct_02080f8c_2* entries; short count; };
extern "C" struct Struct_02080f8c_2* func_0207f6ac(struct Struct_0207f524* list, int id);

struct Container02080f8c { char pad[4]; struct Struct_0207f524 list; };

// USA: func_02080f8c
extern "C" ARM void func_02080f8c(struct Container02080f8c* obj, int id, int value) {
    struct Struct_02080f8c_2* e = func_0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->value = value;
    }
}
