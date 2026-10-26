#include <globaldefs.h>

struct Struct_02080fa8_2 { int value; };
struct Struct_0207f524 { struct Struct_02080fa8_2* entries; short count; };
extern "C" struct Struct_02080fa8_2* func_0207f6ac(struct Struct_0207f524* list, int id);

struct Struct_02080fa8 { char pad[4]; struct Struct_0207f524 list; };

// USA: func_02080fa8
extern "C" ARM void func_02080fa8(struct Struct_02080fa8* obj, int id, int value) {
    struct Struct_02080fa8_2* e = func_0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->value = value;
    }
}
