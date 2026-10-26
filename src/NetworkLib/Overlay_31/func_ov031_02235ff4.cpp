#include <globaldefs.h>

struct Struct_ov031_02235fb0 {
    unsigned char unknown_0_[4];
};

struct Struct_ov031_02235fb0_2 {
    unsigned char padding[0x4c8];
    Struct_ov031_02235fb0 address;
};

extern Struct_ov031_02235fb0_2* data_ov031_02290cfc;
extern const char data_ov031_0224be50[];
extern "C" int func_020c7130(char*, const char*, ...);

// USA: func_ov031_02235ff4
extern "C" ARM void func_ov031_02235ff4(char* destination) {
    Struct_ov031_02235fb0* address = &data_ov031_02290cfc->address;
    unsigned char first = address->unknown_0_[0];
    unsigned char second = address->unknown_0_[1];
    unsigned char third = address->unknown_0_[2];
    unsigned char var4 = address->unknown_0_[3];
    func_020c7130(destination, data_ov031_0224be50, first, second, third, var4);
}
