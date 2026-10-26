#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055080(struct Struct_020546c8* p);

struct Struct_020550f0 {
    char pad[0x10];
    void* field10;
};

// USA: func_020550f0
extern "C" ARM void* func_020550f0(struct Struct_020546c8* p) {
    struct Struct_020550f0* r = (struct Struct_020550f0*)func_02055080(p);
    return r == NULL ? NULL : r->field10;
}
