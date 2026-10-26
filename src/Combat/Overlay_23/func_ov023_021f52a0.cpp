#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021f5410(void*);

// USA: func_ov023_021f52a0
extern "C" ARM void func_ov023_021f52a0(void* obj) {
    memset(obj, 0, 0xc);
    *(int*)((char*)obj + 0x10) = -1;
    func_ov023_021f5410(obj);
}
