#include <globaldefs.h>

// USA: func_0203db24
extern "C" ARM void func_0203db24(unsigned char* obj, int val) {
    int* p = *(int**)(obj + 0x14);
    if (p != NULL) {
        *p = val;
    }
}
