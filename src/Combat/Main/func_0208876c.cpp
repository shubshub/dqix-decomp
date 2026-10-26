#include <globaldefs.h>

struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode);

struct Struct_0208876c {
    unsigned char unknown_0_[0x18];
    unsigned int unknown_18_;
};

// USA: func_0208876c
extern "C" ARM void func_0208876c(struct Struct_0208876c* obj) {
    obj->unknown_18_ |= 0x80;
    func_02088818((struct Struct_020886dc_2*)obj, 3);
}
