#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069eac { void* dest; };

// USA: func_02069eac
extern "C" ARM int func_02069eac(struct Struct_02069eac* obj) {
    void* d = obj->dest;
    unsigned short v = 0xff2f;
    memcpy(d, &v, 2);
    return 2;
}
