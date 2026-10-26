#include <globaldefs.h>

struct Struct_020b01a4 { char pad[0x14]; unsigned int offset; };

// USA: func_020b01e0
extern "C" ARM void func_020b01e0(struct Struct_020b01a4* p) {
    p->offset = p->offset + (unsigned int)p;
}
