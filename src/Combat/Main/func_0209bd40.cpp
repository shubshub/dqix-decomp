#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0209bd40
extern "C" ARM void func_0209bd40(char* obj, int value) {
    int count = *(int*)(obj + 0xc0);
    if (count >= 6) return;
    memset(obj + count * 0x20, 0, 0x20);
    *(short*)(obj + count * 0x20) = value;
    *(int*)(obj + 0xc0) += 1;
}
