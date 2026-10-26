#include <globaldefs.h>

struct Struct_020546c8;
extern "C" void* func_02055090(struct Struct_020546c8* obj);

// USA: func_02055168
extern "C" ARM int func_02055168(struct Struct_020546c8* obj) {
    void* x = func_02055090(obj);
    if (x == NULL) return 0;
    return *(int*)x;
}
