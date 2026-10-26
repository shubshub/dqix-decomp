#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069f4c { void* dest; };

// USA: func_02069f4c
extern "C" ARM int func_02069f4c(struct Struct_02069f4c* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff17;
    memcpy(d, &v, 2);
    return 2;
}
