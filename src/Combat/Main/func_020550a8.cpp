#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055080(struct Struct_020546c8* p);

// USA: func_020550a8
extern "C" ARM void* func_020550a8(struct Struct_020546c8* obj) {
    void* x = func_02055080(obj);
    if (x == NULL) return NULL;
    return *(void**)((char*)x + 4);
}
