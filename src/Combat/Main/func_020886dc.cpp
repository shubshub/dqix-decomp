#include <globaldefs.h>

struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode);

struct Struct_020886dc {
    unsigned char unknown_0_[0x18];
    unsigned int unknown_18_;
};

// USA: func_020886dc
extern "C" ARM void func_020886dc(struct Struct_020886dc* obj) {
    obj->unknown_18_ |= 0x80;
    func_02088818((struct Struct_020886dc_2*)obj, 1);
}
