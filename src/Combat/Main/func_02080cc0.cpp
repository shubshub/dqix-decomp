#include <globaldefs.h>

struct Struct_02080cc0_2 { char pad[0x13]; unsigned char flags; };
struct Struct_0207f524 { struct Struct_02080cc0_2* entries; short count; };
extern "C" struct Struct_02080cc0_2* func_0207f6ac(struct Struct_0207f524* list, int id);

struct Struct_02080cc0 { char pad[4]; struct Struct_0207f524 list; };

// USA: func_02080cc0
extern "C" ARM void func_02080cc0(struct Struct_02080cc0* obj, int id, int value) {
    struct Struct_02080cc0_2* e = func_0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->flags = (e->flags & ~0xf0) | ((value & 0xf) << 4);
    }
}
