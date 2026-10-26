#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov025_021df9b0
extern "C" ARM void func_ov025_021df9b0(void* obj) {
    char* p = (char*)obj;
    *(int*)(p + 0x158) = 0;
    *(int*)(p + 0x15c) = 0;
    *(int*)(p + 0x160) = 0;
    *(int*)(p + 0x164) = 0;
    *(int*)(p + 0x168) = 0;
    *(int*)(p + 0x16c) = 0;
    *(unsigned char*)(p + 0x18a) = 0;
    *(unsigned char*)(p + 0x18b) = 0;
    *(int*)(p + 0x170) = 1;
    memset(p + 0x176, 0, 0x14);
}
