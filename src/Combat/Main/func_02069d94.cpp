#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069d94 { void* dest; };

// USA: func_02069d94
extern "C" ARM int func_02069d94(struct Struct_02069d94* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff13;
    memcpy(d, &v, 2);
    return 2;
}
