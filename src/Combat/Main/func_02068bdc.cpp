#include <globaldefs.h>

// USA: func_02068bdc
extern "C" ARM int func_02068bdc(int a, unsigned char* obj) {
    int v = *(int*)(obj + 0x8c0);
    return v != 0 && v != 1;
}
