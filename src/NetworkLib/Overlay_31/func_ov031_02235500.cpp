#include <globaldefs.h>

struct Struct_ov031_02235500 { unsigned char pad[0x1c]; unsigned char field1c; unsigned char unknown_1d_; };
extern Struct_ov031_02235500* data_ov031_02290cf4;

// USA: func_ov031_02235500
extern "C" ARM void func_ov031_02235500(int a) {
    data_ov031_02290cf4->field1c = (unsigned char)a;
    data_ov031_02290cf4->unknown_1d_ = (a == 2) ? 4 : 6;
}
