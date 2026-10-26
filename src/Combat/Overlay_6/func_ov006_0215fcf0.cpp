// USA: func_ov006_0215fcf0
#include <globaldefs.h>

struct Struct_02081164;
struct Struct_0207fdcc_2;
extern "C" void func_0208103c(void*, int, int);
extern "C" void func_02080798(void*, int, int);
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" int func_020813ec(void*, int);
extern "C" void func_02080c68(void*, int, int);
extern "C" void func_02080c20(Struct_0207fdcc_2*, int);

struct Struct_ov006_0215fcf0 {
#if defined(jpn)
    unsigned char unknown[0xc];
    void* menu;
    unsigned char unknown_10_[0x386 - 0x10];
#else
    unsigned char unknown[0x14];
    void* menu;
    unsigned char unknown_18_[0x386 - 0x18];
#endif
    unsigned char unknown_386_;
};

extern "C" ARM void func_ov006_0215fcf0(Struct_ov006_0215fcf0* owner) {
    void* menu = owner->menu;
    int var1 = (short)(owner->unknown_386_ + 0x29);
    func_0208103c(menu, 0x5a, var1);
#if !defined(jpn)
    func_02080798(menu, 0x5a, 1);
#endif
    func_02081164((Struct_02081164*)menu, 0xf, 1);
    func_020813ec(menu, 0xf);
    func_02080c68(menu, 0xf, 2);
    func_02080c20((Struct_0207fdcc_2*)menu, 0xf);
}
