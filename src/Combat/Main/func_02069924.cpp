#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069924 { char* dst; };

// USA: func_02069924
extern "C" ARM int func_02069924(struct Struct_02069924* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff26;
    memcpy(d, &v, 2);
    return 2;
}
