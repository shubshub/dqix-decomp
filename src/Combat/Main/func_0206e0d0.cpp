#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206e0d0
extern "C" ARM void func_0206e0d0(char* base, int index) {
    char* entry = base + index * 0x1c;
    memset(entry + 0x10, 0, 4);
    memset(entry + 0x14, 0, 8);
}
