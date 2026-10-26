#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055080(struct Struct_020546c8* p);

struct Struct_02055120 {
    char pad[0x18];
    void* field18;
};

// USA: func_02055120
extern "C" ARM void* func_02055120(struct Struct_020546c8* p) {
    struct Struct_02055120* r = (struct Struct_02055120*)func_02055080(p);
    return r == NULL ? NULL : r->field18;
}
