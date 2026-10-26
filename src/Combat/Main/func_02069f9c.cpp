#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069f9c { void* dst; };

// USA: func_02069f9c
extern "C" ARM int func_02069f9c(struct Struct_02069f9c* p) {
    void* d = p->dst;
    unsigned short code = 0xff03;
    memcpy(d, &code, 2);
    return 2;
}
