#include <globaldefs.h>

extern "C" void func_02088d4c(unsigned char* obj);

// USA: func_02088ccc
extern "C" ARM void func_02088ccc(unsigned char* obj) {
    obj[0x6b] = 5;
    obj[0x8e] = 0;
    *(int*)(obj + 0x18) |= 0x8;
    func_02088d4c(obj);
}
