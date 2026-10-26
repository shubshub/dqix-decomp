#include <globaldefs.h>

struct Struct_ov031_02290ca0_26 {
    unsigned char unk0;
    unsigned char unknown_1_;
};
extern struct Struct_ov031_02290ca0_26 data_ov031_02290ca0;

// USA: func_ov031_02230ef0
extern "C" ARM void func_ov031_02230ef0(unsigned char val) {
    data_ov031_02290ca0.unknown_1_ = val;
}
