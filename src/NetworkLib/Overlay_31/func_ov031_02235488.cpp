#include <globaldefs.h>

extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_0223689c(int val);
extern "C" void func_ov031_022368bc(int arg0, int arg1);

struct Struct_ov031_02235488 { unsigned char pad[0x1a]; unsigned char unknown_1a_; };
extern Struct_ov031_02235488* data_ov031_02290cf4;

// USA: func_ov031_02235488
extern "C" ARM void func_ov031_02235488(int arg0) {
    int diff = data_ov031_02290cf4->unknown_1a_ - arg0;
    int var1 = diff < 0 ? -diff : diff;
    int level;
    if (var1 < 2) {
        level = 0;
    } else if (var1 >= 6) {
        level = 0x7f;
    } else {
        level = FastIntDivide(0x7f, 6 - var1);
    }
    func_ov031_0223689c(level);

    int v;
    if (var1 < 2) {
        v = -256;
    } else if (var1 >= 6) {
        v = 256;
    } else {
        v = FastIntDivide(0x200, 6 - var1) - 0x100;
    }
    func_ov031_022368bc(0xffff, v);
}
