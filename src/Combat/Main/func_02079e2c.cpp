#include <globaldefs.h>

struct Struct_02079e2c;
typedef int (*Type_02079e2c)(void*);
extern "C" void* func_02079e60(struct Struct_02079e2c* obj, int key, Type_02079e2c arg2);

struct Struct_020797e8;
extern "C" int func_020797e8(struct Struct_020797e8* p);

// USA: func_02079e2c
extern "C" ARM void* func_02079e2c(char* p, int key) {
    void* r = func_02079e60((struct Struct_02079e2c*)p, key, (Type_02079e2c)func_020797e8);
    if (r != 0) return r;
    return func_02079e60((struct Struct_02079e2c*)(p + 0xc), key, (Type_02079e2c)func_020797e8);
}
