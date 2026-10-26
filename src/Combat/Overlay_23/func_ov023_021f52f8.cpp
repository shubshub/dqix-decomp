#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov023_021f5410(void* a);
extern "C" int func_ov023_021f5340(void* a);

// USA: func_ov023_021f52f8
extern "C" ARM int func_ov023_021f52f8(void* a, void* b) {
    func_ov023_021f5410(a);
    memset(a, 0, 0xc);
    *(int*)((char*)a + 0x10) = -1;
    func_ov023_021f5410(a);
    *(void**)((char*)a + 0x14) = b;
    *(short*)((char*)a + 0xc) = 1;
    return func_ov023_021f5340(a);
}
