#include <globaldefs.h>

struct Struct_ov031_02237e9c { unsigned char pad[0x1b]; signed char unknown_1b_; };
extern Struct_ov031_02237e9c* data_ov031_02290d10;

// USA: func_ov031_02237e9c
extern "C" ARM signed char func_ov031_02237e9c(void) {
    return data_ov031_02290d10->unknown_1b_;
}
