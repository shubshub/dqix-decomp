#include <globaldefs.h>

struct Struct_0207f6ac;
struct Struct_0207f524;
extern "C" struct Struct_0207f6ac* func_0207f6ac(struct Struct_0207f524*, int);

// USA: func_02080854
extern "C" ARM void func_02080854(void* obj, int id, int x, int y) {
    struct Struct_0207f6ac* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 0x4), id);
    if (e != NULL) {
        *(short*)((char*)e + 0x6) = x;
        *(short*)((char*)e + 0x8) = y;
    }
}
