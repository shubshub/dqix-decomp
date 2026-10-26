#include <globaldefs.h>

struct Struct_ov031_0224f670_18 {
    char unknown_0_[0x38];
    int phase;
    char unknown_3c_[0x78 - 0x3c];
    int result;
};
struct Struct_ov031_0224b114_4 {
    char padding[0xc];
    int active;
};
extern Struct_ov031_0224f670_18 data_ov031_0224f670;
extern Struct_ov031_0224b114_4 data_ov031_0224b114;
extern "C" int func_ov031_02220af0();
extern "C" void func_ov031_0221fcb4();
extern "C" void func_ov031_02222af0();

// USA: func_ov031_02220ed4
extern "C" THUMB void func_ov031_02220ed4() {
    int result = func_ov031_02220af0();
    data_ov031_0224f670.result = result;
    func_ov031_0221fcb4();
    if (result == 1) data_ov031_0224f670.phase = 6;
    else data_ov031_0224f670.phase = 7;
    data_ov031_0224b114.active = -1;
    func_ov031_02222af0();
}
