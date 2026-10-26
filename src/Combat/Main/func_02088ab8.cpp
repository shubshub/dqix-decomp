#include <globaldefs.h>

// USA: func_02088ab8
extern "C" ARM int func_02088ab8(unsigned char* obj) {
    if (((int*)obj)[5] & 1) {
        return 0;
    }
    return (((int*)obj)[6] & 0x40) == 0;
}
