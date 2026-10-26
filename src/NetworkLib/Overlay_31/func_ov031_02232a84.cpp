#include <globaldefs.h>

struct Struct_ov031_02232a84 { unsigned char pad[0x1d]; unsigned char unknown_1d_; };
struct Struct_ov031_02290cc0_4 { unsigned char field0; unsigned char pad[3]; Struct_ov031_02232a84 *unknown_4_; };
extern Struct_ov031_02290cc0_4 data_ov031_02290cc0;
extern "C" void func_ov031_02236e60(void);
extern "C" void func_ov031_02222e98(void);
extern "C" void func_ov031_0223c278(int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02232ac0(void);

// USA: func_ov031_02232a84
extern "C" ARM void func_ov031_02232a84(void) {
	if (data_ov031_02290cc0.unknown_4_->unknown_1d_ == 2) {
		func_ov031_02236e60();
	}
	func_ov031_02222e98();
	func_ov031_0223c278(8);
	func_ov031_022274c0((int)func_ov031_02232ac0);
}
