#include <globaldefs.h>

extern "C" void func_02088cf4(unsigned char* obj);

// USA: func_02088d24
extern "C" ARM void func_02088d24(unsigned char* obj) {
    obj[0x7b] = 5;
    obj[0x9e] = 0;
    *(int*)(obj + 0x18) |= 0x10;
    func_02088cf4(obj);
}
