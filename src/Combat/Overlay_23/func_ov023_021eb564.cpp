#include <globaldefs.h>

// USA: func_ov023_021eb564
extern "C" ARM void func_ov023_021eb564(char* obj, int a, int b) {
    if (a != 0 && b != 0) {
        *(int*)(obj + 0x20) = a;
        *(int*)(obj + 0x24) = b;
    }
}
