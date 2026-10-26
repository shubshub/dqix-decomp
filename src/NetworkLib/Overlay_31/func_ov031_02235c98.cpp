#include <globaldefs.h>

struct Struct_ov031_02235c98 { unsigned char pad[0x4f6]; unsigned char unknown_4f6_; };
extern Struct_ov031_02235c98* data_ov031_02290cfc;

// USA: func_ov031_02235c98
extern "C" ARM void func_ov031_02235c98(unsigned char val) {
    data_ov031_02290cfc->unknown_4f6_ = val;
}
