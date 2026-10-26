#include <globaldefs.h>
#include "std_library_functions.h"

unsigned long long GetCurrentTimestamp(void);

// USA: func_ov023_021db0d4
extern "C" ARM void func_ov023_021db0d4(void* obj, int flag) {
    char* o = (char*)obj;
    *(unsigned char*)(o + 0x24) = (unsigned char)flag;
    *(short*)(o + 0x20) = 0;
    *(short*)(o + 0x22) = 0;
    memset(o, 0, 0x18);
    *(short*)(o + 0x2) = 0xf;
    *(short*)(o + 0xa) = 0xf;
    *(short*)(o + 0x12) = 0x17;
    GetCurrentTimestamp();
}
