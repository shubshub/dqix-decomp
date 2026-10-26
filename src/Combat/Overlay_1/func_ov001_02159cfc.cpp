#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_ov001_02164d10;

// USA: func_ov001_02159cfc
extern "C" ARM void func_ov001_02159cfc(char* obj) {
    *(int*)(obj + 0x0) = 0;
    memset(obj + 0x4, 0, 0xc);
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    strcpy(obj + 0x1c, &data_ov001_02164d10);
    *(int*)(obj + 0x3c) = 0;
}
