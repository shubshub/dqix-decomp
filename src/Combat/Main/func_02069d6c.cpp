#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069d6c { void* dest; };

// USA: func_02069d6c
extern "C" ARM int func_02069d6c(struct Struct_02069d6c* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff11;
    memcpy(d, &v, 2);
    return 2;
}
