#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069ce0 { void* dest; };

// USA: func_02069ce0
extern "C" ARM int func_02069ce0(struct Struct_02069ce0* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff0f;
    memcpy(d, &v, 2);
    return 2;
}
