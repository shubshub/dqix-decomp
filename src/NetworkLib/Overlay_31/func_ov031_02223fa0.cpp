#include <globaldefs.h>

struct Struct_ov031_02223fa0 { unsigned char pad[0x11c]; unsigned char field11c; };
extern Struct_ov031_02223fa0* data_ov031_02250bfc;

// USA: func_ov031_02223fa0
extern "C" ARM unsigned char func_ov031_02223fa0(void) {
    return data_ov031_02250bfc->field11c;
}
