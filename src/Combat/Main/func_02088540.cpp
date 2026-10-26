#include <globaldefs.h>

// USA: func_02088540
extern "C" ARM int func_02088540(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    return (x & 0x1000000) == 0;
}
