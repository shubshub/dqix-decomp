#include <globaldefs.h>

struct Struct_0207f524;
extern "C" int func_0207f7cc(struct Struct_0207f524*, int, int);

// USA: func_02080b40
extern "C" ARM int func_02080b40(void* obj, int id) {
    return func_0207f7cc((struct Struct_0207f524*)((char*)obj + 4), id, 1);
}
