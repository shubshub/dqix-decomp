#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206e080
extern "C" ARM void func_0206e080(char* base, int index) {
    char* obj = base + index * 0x1c;
    memset(obj + 0x3, 0, 4);
    memset(obj + 0x8, 0, 8);
    memset(obj + 0x10, 0, 4);
    memset(obj + 0x14, 0, 8);
}
