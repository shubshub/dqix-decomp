#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069f24 { void* dest; };

// USA: func_02069f24
extern "C" ARM int func_02069f24(struct Struct_02069f24* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff16;
    memcpy(d, &v, 2);
    return 2;
}
