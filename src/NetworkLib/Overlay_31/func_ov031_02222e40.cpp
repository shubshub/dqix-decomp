#include <globaldefs.h>
struct Struct_ov031_02222e40 { unsigned char pad[0x16]; signed char unknown_16_; };
extern Struct_ov031_02222e40* data_ov031_02250ba8;

// USA: func_ov031_02222e40
extern "C" ARM void func_ov031_02222e40(int v) {
	data_ov031_02250ba8->unknown_16_ = (signed char)v;
}
