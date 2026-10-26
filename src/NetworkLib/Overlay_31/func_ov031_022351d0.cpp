#include <globaldefs.h>

struct Struct_ov031_022351d0 { unsigned char pad[0x1a]; unsigned char unknown_1a_; };
extern Struct_ov031_022351d0* data_ov031_02290cf4;

// USA: func_ov031_022351d0
extern "C" ARM unsigned char func_ov031_022351d0(void) {
    return data_ov031_02290cf4->unknown_1a_;
}
