#include <globaldefs.h>

struct Struct_ov031_02223fc8 { unsigned char pad[0x124]; unsigned char field124; };
extern Struct_ov031_02223fc8* data_ov031_02250bfc;

// USA: func_ov031_02223fc8
extern "C" ARM void func_ov031_02223fc8(int v) {
    data_ov031_02250bfc->field124 = (unsigned char)v;
}
