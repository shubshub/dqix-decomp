#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov004_021698f4 { char pad[0x20]; void* ptr; unsigned short w; unsigned short h; };

// USA: func_ov023_021f9c0c
extern "C" ARM void* func_ov023_021f9c0c(struct Struct_ov004_021698f4* obj) {
    unsigned short w = obj->w;
    unsigned short h = obj->h;
    void* ptr = obj->ptr;
    return memset(ptr, 0, h * (w * 2));
}
