#include <globaldefs.h>

extern "C" int func_020d1e08(int a, int b, int c, int d);
extern "C" int func_020d1ebc(int a, int b, int c);
struct Struct_020bc4f8;
extern "C" void func_020bc610(Struct_020bc4f8* obj);
extern "C" int func_020d26ec(void);

struct Struct_020bc4f8_2 { unsigned char pad[0x1c]; int field1c; };

struct Struct_020bc4f8_3 {
    unsigned char unknown_0_[4];
    Struct_020bc4f8_2* field4;
    unsigned char pad08[0x24];
    unsigned char unknown_2c_;
    unsigned char unknown_2d_[2];
    unsigned char unknown_2f_;
    int unknown_30_;
    unsigned char unknown_34_[8];
    unsigned char unknown_3c_;
};

// USA: func_020bc4f8
extern "C" ARM void func_020bc4f8(Struct_020bc4f8_3* obj, int b, int c, int d) {
    Struct_020bc4f8_2* p = obj->field4;
    func_020d1e08(obj->unknown_3c_, b, c, d);
    if (p->field1c != 0) {
        func_020d1ebc(obj->unknown_3c_, 0xffff, p->field1c);
    }
    func_020bc610((Struct_020bc4f8*)obj);
    obj->unknown_30_ = func_020d26ec();
    obj->unknown_2f_ = 1;
    obj->unknown_2c_ = 1;
}
