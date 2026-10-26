#include <globaldefs.h>

struct Struct_020546c8 {
    char pad[0x4];
    void* field4;
};

// USA: func_02055080
extern "C" ARM void* func_02055080(struct Struct_020546c8* p) {
    void* x = p->field4;
    return x != NULL ? x : NULL;
}
