#include <globaldefs.h>

struct Struct_ov031_02232ac0 { unsigned char pad[0x1d]; unsigned char unknown_1d_; };
struct Struct_ov031_02290cc0_5 { unsigned char field0; unsigned char pad[3]; Struct_ov031_02232ac0 *unknown_4_; };
extern Struct_ov031_02290cc0_5 data_ov031_02290cc0;
extern "C" int func_ov031_0223c054(int);
extern "C" int func_ov031_02222ddc(void);
extern "C" char* func_ov031_02235c70(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02232b44(void);

// USA: func_ov031_02232ac0
extern "C" ARM void func_ov031_02232ac0(void) {
	if (func_ov031_0223c054(1) != 0) return;

	if (data_ov031_02290cc0.unknown_4_->unknown_1d_ == 1) {
		if (data_ov031_02290cc0.field0 == 3 ||
		    *(unsigned char*)(func_ov031_02235c70() + 0xe7) != 0xff) {
			func_ov031_02222ddc();
		}
	}

	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x14, 8);
	func_ov031_022274c0((int)func_ov031_02232b44);
}
