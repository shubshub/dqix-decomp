#include <globaldefs.h>

extern "C" int FastIntDivide(int arg0, unsigned int arg1);

struct Struct_ov031_02290ca0_16 {
    unsigned char unk0;
    unsigned char unknown_1_;
    unsigned char unk2;
    unsigned char unknown_3_;
    unsigned short field4;
};
extern struct Struct_ov031_02290ca0_16 data_ov031_02290ca0;

// USA: func_ov031_022305e8
extern "C" ARM int func_ov031_022305e8(int a) {
    int var0 = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
    return var0 + a;
}
