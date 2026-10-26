#include <globaldefs.h>

extern "C" void func_02088c9c(unsigned char* obj);

// USA: func_02088c10
extern "C" ARM void func_02088c10(unsigned char* obj) {
    obj[0x6c] = 5;
    obj[0x8f] = 0;
    *(int*)(obj + 0x18) |= 0x2;
    func_02088c9c(obj);
}
