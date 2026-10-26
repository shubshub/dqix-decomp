#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_02157cdc
extern "C" ARM void func_ov000_02157cdc(void* obj) {
    memset(obj, 0, 0x20);
    memset((char*)obj + 0xe, -1, 6);
    *(short*)((char*)obj + 0xc) = -1;
    *(int*)((char*)obj + 0x20) = 0;
}
