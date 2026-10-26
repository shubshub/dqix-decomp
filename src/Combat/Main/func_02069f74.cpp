#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069f74 { void* dst; };

// USA: func_02069f74
extern "C" ARM int func_02069f74(struct Struct_02069f74* p) {
    void* d = p->dst;
    unsigned short code = 0xff01;
    memcpy(d, &code, 2);
    return 2;
}
