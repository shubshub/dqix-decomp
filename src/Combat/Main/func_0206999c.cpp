#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0206999c { char* dst; };

// USA: func_0206999c
extern "C" ARM int func_0206999c(struct Struct_0206999c* obj) {
    char* d = obj->dst;
    unsigned short v = 0xff29;
    memcpy(d, &v, 2);
    return 2;
}
