#include <globaldefs.h>

struct Struct_ov031_02227cb0 { unsigned int v[3]; };
extern Struct_ov031_02227cb0* data_ov031_02290c48;

// USA: func_ov031_02227cb0
extern "C" ARM void func_ov031_02227cb0(Struct_ov031_02227cb0* src) {
    *data_ov031_02290c48 = *src;
}
