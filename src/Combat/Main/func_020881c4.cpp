#include <globaldefs.h>

// USA: func_020881c4
extern "C" ARM int func_020881c4(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    if (x & 0x1000000) {
        return 0;
    }
    if (x & 0x10) {
        return 0;
    }
    if (x & 0x80000) {
        return 0;
    }
    return (x & 0x8) == 0;
}
