#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055080(struct Struct_020546c8* p);

struct Struct_02055108 {
    char pad[0x14];
    void* field14;
};

// USA: func_02055108
extern "C" ARM void* func_02055108(struct Struct_020546c8* p) {
    struct Struct_02055108* r = (struct Struct_02055108*)func_02055080(p);
    return r == NULL ? NULL : r->field14;
}
