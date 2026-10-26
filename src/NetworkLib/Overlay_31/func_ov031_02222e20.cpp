#include <globaldefs.h>
struct Struct_ov031_02222e20 { unsigned char pad[0x16]; signed char unknown_16_; };
extern Struct_ov031_02222e20* data_ov031_02250ba8;

// USA: func_ov031_02222e20
extern "C" ARM void func_ov031_02222e20(int v) {
	if (data_ov031_02250ba8->unknown_16_ == -1) {
		data_ov031_02250ba8->unknown_16_ = (signed char)v;
	}
}
