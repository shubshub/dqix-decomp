#include <globaldefs.h>

// USA: func_020883ac
extern "C" ARM int func_020883ac(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    return (x & 0x1000000) == 0;
}
