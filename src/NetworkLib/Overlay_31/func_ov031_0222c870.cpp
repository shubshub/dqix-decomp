#include <globaldefs.h>

extern "C" int FastIntModulus(int, int);

struct Struct_ov031_0222c870;
struct Struct_ov031_02290c8c_16 {
    unsigned char pad[2];
    unsigned short field2;
    Struct_ov031_0222c870* field4;
};
struct Struct_ov031_0222c870 { unsigned char pad[0x56]; unsigned char unknown_56_; };
extern Struct_ov031_02290c8c_16 data_ov031_02290c8c;

// USA: func_ov031_0222c870
extern "C" ARM void func_ov031_0222c870(void) {
    if (data_ov031_02290c8c.field4->unknown_56_ == 0) return;
    int rem = FastIntModulus(data_ov031_02290c8c.field2, 0x1c);
    unsigned int val = ((rem - 0x32) << 16) & 0x1ff0000;
    *(volatile unsigned int*)0x4000010 = val;
    *(volatile unsigned int*)0x4000018 = val;
    data_ov031_02290c8c.field4->unknown_56_ = 0;
}
