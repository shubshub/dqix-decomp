#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0204a4ac(void*);

// USA: func_0204a440
extern "C" ARM void func_0204a440(char* obj, const char* src) {
    strcpy(obj + 0x224, src);
    *(int*)(obj + 0x254) = -1;
    func_0204a4ac(obj);
}
