#include <globaldefs.h>

extern "C" int func_020d1e70(int a, int b);
extern "C" int func_020d1de8(int a);
extern "C" void func_020bc79c(void*);

struct Struct_020bc2f0_2 {
    char pad0[0x2c];
    unsigned char field2c;
    char unknown_2d_[0x3c - 0x2d];
    unsigned char field3c;
};

// USA: func_020bc6fc
extern "C" ARM void func_020bc6fc(struct Struct_020bc2f0_2* obj) {
    if (obj->field2c == 2) {
        func_020d1e70(obj->field3c, 0xfffffd2d);
    }
    func_020d1de8(obj->field3c);
    func_020bc79c(obj);
}
