#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069974 { char* dst; };

// USA: func_02069974
extern "C" ARM int func_02069974(struct Struct_02069974* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff28;
    memcpy(d, &v, 2);
    return 2;
}
