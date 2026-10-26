#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215f9e8_20 = 0xc };
#else
enum { Enum_ov006_0215f9e8_20 = 0x14 };
#endif

struct Struct_02080fa8;
struct Struct_ov006_0215f9e8 {
    unsigned char unknown[Enum_ov006_0215f9e8_20];
    Struct_02080fa8* menu;
    unsigned char unknown_18_[0x36e - Enum_ov006_0215f9e8_20 - 4];
    unsigned short group;
    unsigned char unknown_370_[0x38b - 0x370];
    unsigned char value;
};

extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" int func_020813ec(void*, int);

// USA: func_ov006_0215f9e8
extern "C" ARM void func_ov006_0215f9e8(Struct_ov006_0215f9e8* self) {
    func_02080fa8(self->menu, 0x3d, self->value);
    func_020813ec(self->menu, 10);
    self->group = 10;
}
