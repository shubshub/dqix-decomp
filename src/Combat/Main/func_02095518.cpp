#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02095518
extern "C" ARM void func_02095518(char* obj) {
    *(int*)(obj + 0xa0) = 0;
    *(int*)(obj + 0xa4) = 0;
    *(int*)(obj + 0xa8) = 0;
    *(int*)(obj + 0x4c4) = -1;
    memset(obj, 0, 0xa0);
    memset(obj + 0xac, 0xff, 0xcc);
    memset(obj + 0x178, 0, 0x330);
    memset(obj + 0x4a8, 0, 0x1a);
}
