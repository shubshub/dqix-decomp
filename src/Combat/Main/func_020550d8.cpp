#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055080(struct Struct_020546c8* p);

struct Struct_020550d8 {
    char pad[0xc];
    void* fieldC;
};

// USA: func_020550d8
extern "C" ARM void* func_020550d8(struct Struct_020546c8* p) {
    struct Struct_020550d8* r = (struct Struct_020550d8*)func_02055080(p);
    return r == NULL ? NULL : r->fieldC;
}
