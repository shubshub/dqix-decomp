#include <globaldefs.h>

struct Struct_0207f0ac_2;
struct Struct_0207f0ac;
extern "C" struct Struct_0207f0ac_2* func_0207f0ac(struct Struct_0207f0ac*, int);

// USA: func_02080878
extern "C" ARM void func_02080878(void* obj, int id, short* outX, short* outY) {
    struct Struct_0207f0ac_2* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *outX = *(short*)((char*)e + 0xe);
        *outY = *(short*)((char*)e + 0x10);
    }
}
