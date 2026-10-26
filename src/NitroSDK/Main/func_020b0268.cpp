#include <globaldefs.h>

struct Struct_020b022c { char pad[0x4]; unsigned int offset; };

// USA: func_020b0268
extern "C" ARM void func_020b0268(struct Struct_020b022c* p) {
    p->offset = p->offset + (unsigned int)p;
}
