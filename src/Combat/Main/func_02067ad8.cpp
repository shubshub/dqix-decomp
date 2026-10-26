#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02067ad8
extern "C" ARM int func_02067ad8(int unused, void* src) {
    unsigned short val;
    memcpy(&val, src, 2);
    if (val >= 0xff01 && val <= 0xff18) return 1;
    return (val & 0xffe0) == 0xffe0;
}
