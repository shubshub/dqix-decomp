#include <globaldefs.h>

extern "C" int func_02088e04(unsigned char* obj);

// USA: func_02088dd8
extern "C" ARM int func_02088dd8(unsigned char* obj) {
    if (func_02088e04(obj) == 0) {
        return 0;
    }
    return (*(int*)(obj + 0x18) & 0x1000) == 0;
}
