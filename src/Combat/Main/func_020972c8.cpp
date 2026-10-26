#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020972c8
extern "C" ARM void func_020972c8(int* p) {
    *p = 0;
    memset(p + 1, 0, 0xc);
}
