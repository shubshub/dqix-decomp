#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0209fe9c
extern "C" ARM void func_0209fe9c(char* obj) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 4) = 0;
    *(int*)(obj + 8) = 0;
    *(int*)(obj + 0x60) = -1;
    *(int*)(obj + 0x64) = -1;
    *(short*)(obj + 0x68) = 0;
    memset(obj + 0xc, 0, 0x54);
    memset(obj + 0x6a, 0, 0x64);
}
