#include <globaldefs.h>

struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode);

// USA: func_020887fc
extern "C" ARM void func_020887fc(unsigned char* obj) {
    *(int*)(obj + 0x18) |= 0x80;
    func_02088818((struct Struct_020886dc_2*)obj, 5);
}
