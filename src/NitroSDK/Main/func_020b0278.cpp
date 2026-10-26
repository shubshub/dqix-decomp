#include <globaldefs.h>

struct Struct_020b01f0 { char pad[0xc]; unsigned int offset; };

// USA: func_020b0278
extern "C" ARM void func_020b0278(struct Struct_020b01f0* p) {
    p->offset = p->offset + (unsigned int)p;
}
