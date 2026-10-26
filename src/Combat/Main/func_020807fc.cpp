#include <globaldefs.h>

struct Struct_0207f0ac_2;
struct Struct_0207f0ac;
extern "C" struct Struct_0207f0ac_2* func_0207f0ac(struct Struct_0207f0ac*, int);

// USA: func_020807fc
extern "C" ARM void func_020807fc(void* obj, int id, int x, int y) {
    struct Struct_0207f0ac_2* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *(short*)((char*)e + 0xa) = x >> 3;
        *(short*)((char*)e + 0xc) = y >> 3;
    }
}
