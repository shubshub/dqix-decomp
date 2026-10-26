#include <globaldefs.h>

extern "C" int func_ov031_02239be8(void);
extern "C" void func_ov031_0223a47c(void);

struct Struct_ov031_0223b010 { unsigned char pad[0xa90]; unsigned char unknown_a90_; };
extern struct Struct_ov031_0223b010* data_ov031_02290d20;

// USA: func_ov031_0223b010
extern "C" ARM int func_ov031_0223b010(void) {
	if (func_ov031_02239be8() != 1) return 0;
	func_ov031_0223a47c();
	data_ov031_02290d20->unknown_a90_ = 1;
	return 1;
}
