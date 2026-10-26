#include <globaldefs.h>

// USA: func_02088e04
extern "C" ARM int func_02088e04(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    if (x & 0x10) {
        return 0;
    }
    if (x & 0x80000) {
        return 0;
    }
    if (x & 0x8) {
        return 0;
    }
    return (x & 0x20) == 0;
}
