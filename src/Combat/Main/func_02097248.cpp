#include <globaldefs.h>

extern "C" int func_02097280(void*, int, int);

struct Struct_02097248 { int f0; int f4; int f8; };

// USA: func_02097248
extern "C" ARM int func_02097248(void* a, struct Struct_02097248* b) {
    b->f4 = func_02097280(a, b->f4, 0);
    b->f8 = func_02097280(a, b->f8, 0);
    return 1;
}
