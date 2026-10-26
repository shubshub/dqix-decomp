#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_02160030
extern "C" ARM void func_ov000_02160030(void* obj) {
    memset(obj, 0, 0x28);
    *(short*)((char*)obj + 0x6) = -1;
    memset((char*)obj + 0x18, 0, 0xe);
    *(short*)((char*)obj + 0x24) = 0;
}
