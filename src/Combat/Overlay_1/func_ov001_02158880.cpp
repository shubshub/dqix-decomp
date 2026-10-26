#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov001_021588e4(void* obj);

// USA: func_ov001_02158880
extern "C" ARM void func_ov001_02158880(void* obj) {
    *(int*)((char*)obj + 0x0) = 0;
    *(int*)((char*)obj + 0x4) = 0;
    memset((char*)obj + 0x4c, 0, 0xc);
    memset((char*)obj + 0x58, 0, 0xc);
    func_ov001_021588e4(obj);
}
