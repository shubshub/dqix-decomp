#include <globaldefs.h>

struct Struct_ov031_0223521c { unsigned char pad[0x1e]; unsigned char unknown_1e_; };
extern Struct_ov031_0223521c* data_ov031_02290cf4;

// USA: func_ov031_0223521c
extern "C" ARM void func_ov031_0223521c(void) {
    data_ov031_02290cf4->unknown_1e_ = 1;
}
