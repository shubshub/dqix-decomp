#include <globaldefs.h>

struct Struct_ov031_022351e4 { unsigned char pad[0x1d]; unsigned char unknown_1d_; };
extern Struct_ov031_022351e4* data_ov031_02290cf4;

// USA: func_ov031_022351e4
extern "C" ARM unsigned char func_ov031_022351e4(void) {
    return data_ov031_02290cf4->unknown_1d_;
}
