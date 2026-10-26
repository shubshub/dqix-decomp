#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206e70c
extern "C" ARM void func_0206e70c(char* obj) {
    memcpy(obj + 0x334, obj, 0xce);
    *(int*)(obj + 0x404) = 0;
    memcpy(obj + 0x40c, obj + 0x323, 0xf);
}
