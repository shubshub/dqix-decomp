#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02069fc4 { void* dst; };

// USA: func_02069fc4
extern "C" ARM int func_02069fc4(struct Struct_02069fc4* p) {
    void* d = p->dst;
    unsigned short code = 0xff0e;
    memcpy(d, &code, 2);
    return 2;
}
