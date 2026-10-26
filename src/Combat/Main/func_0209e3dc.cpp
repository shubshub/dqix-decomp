#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0209e3dc
extern "C" ARM void func_0209e3dc(char* obj, int param2) {
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = param2;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x64) = -1;
    *(int*)(obj + 0x68) = -1;
    *(int*)(obj + 0x6c) = -1;
    memset(obj + 0x70, 0, 0x10);
    *(int*)(obj + 0x90) = -1;
    *(int*)(obj + 0x94) = 0;
    *(int*)(obj + 0x98) = 0;
    memset(obj + 0x9c, 0, 0x400);
    *(int*)(obj + 0x49c) = 0;
    memset(obj + 0x4a0, 0, 0x400);
    memset(obj + 0x10, 0, 0x54);
    *(int*)(obj + 0x84) = 0;
    *(int*)(obj + 0x88) = 0;
    *(int*)(obj + 0x8c) = 0;
}
