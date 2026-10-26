#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0209e46c
extern "C" ARM void func_0209e46c(char* obj) {
    *(int*)(obj + 0x6c) = -1;
    memset(obj + 0x70, 0, 0x10);
    *(int*)(obj + 0x90) = -1;
    *(int*)(obj + 0x94) = 0;
}
