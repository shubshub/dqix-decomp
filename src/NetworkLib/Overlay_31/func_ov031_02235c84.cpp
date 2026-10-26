#include <globaldefs.h>

struct Struct_ov031_02235c84 { unsigned char pad[0x4f5]; unsigned char unknown_4f5_; };
extern Struct_ov031_02235c84* data_ov031_02290cfc;

// USA: func_ov031_02235c84
extern "C" ARM void func_ov031_02235c84(unsigned char val) {
    data_ov031_02290cfc->unknown_4f5_ = val;
}
