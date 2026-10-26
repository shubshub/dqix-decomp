#include <globaldefs.h>

struct Struct_ov031_02223fb4 { unsigned char pad[0x123]; unsigned char unknown_123_; };
extern Struct_ov031_02223fb4* data_ov031_02250bfc;

// USA: func_ov031_02223fb4
extern "C" ARM void func_ov031_02223fb4(int v) {
    data_ov031_02250bfc->unknown_123_ = (unsigned char)v;
}
