#include <globaldefs.h>

extern "C" int func_020d1ee4(int a, int b, int c, int d);
struct Struct_0210cfd0;
struct Struct_0210cfdc;
extern "C" void func_020cef34(struct Struct_0210cfd0*);
extern "C" void func_020cef4c(struct Struct_0210cfdc*);

struct Struct_020bcb70 {
    char pad0[8];
    char unknown_8_[0xc];
    char unknown_14_[0x10];
    int field24;
    char pad28[0x18];
    int field40;
    int field44;
};

// USA: func_020bcb70
extern "C" ARM void func_020bcb70(struct Struct_020bcb70* obj) {
    func_020d1ee4(obj->field44, 0, 1 << obj->field40, 0);
    if ((obj->field24 << 30) >> 31) return;
    func_020cef34((struct Struct_0210cfd0*)&obj->unknown_8_);
    func_020cef4c((struct Struct_0210cfdc*)&obj->unknown_14_);
    obj->field24 |= 2;
}
