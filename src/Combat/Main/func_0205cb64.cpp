#include <globaldefs.h>

struct Struct_0205c570;
extern "C" int func_0205c570(struct Struct_0205c570* s);

// USA: func_0205cb64
extern "C" ARM int func_0205cb64(void* obj) {
    return func_0205c570((struct Struct_0205c570*)((char*)obj + 0x1c));
}
