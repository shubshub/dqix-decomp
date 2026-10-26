#include <globaldefs.h>

extern "C" void func_02087efc(unsigned char* p);
extern "C" void func_02088c38(unsigned char* p);
extern "C" void func_02088c9c(unsigned char* p);

struct Struct_02087e6c {
    char pad0[0x14];
    int field14;
    char pad18[0x58 - 0x18];
    int unknown_58_0_ : 21;
    int unknown_5a_5_ : 3;
    char unknown_5b_[0x75 - 0x5c];
    unsigned char unknown_74_;
    char unknown_75_[0x98 - 0x76];
    unsigned char unknown_97_;
};

// USA: func_02087e6c
extern "C" ARM int func_02087e6c(struct Struct_02087e6c* obj, int delta) {
    int val = delta + obj->unknown_5a_5_;

    if (val > 2) {
        val = 2;
    }
    if (val < -2) {
        val = -2;
    }

    if (val == 0) {
        func_02087efc((unsigned char*)obj);
        return 0;
    }

    obj->unknown_5a_5_ = val;
    obj->unknown_74_ = 5;
    obj->unknown_97_ = 0;
    obj->field14 |= 0x20000;
    func_02088c38((unsigned char*)obj);
    func_02088c9c((unsigned char*)obj);
    return obj->unknown_5a_5_;
}
