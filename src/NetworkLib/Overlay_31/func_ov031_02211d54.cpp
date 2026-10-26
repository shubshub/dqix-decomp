#include <globaldefs.h>

struct Struct_ov031_02211d54 { unsigned char pad[0xc]; unsigned char fieldc; };
struct Struct_ov031_0224e5b4_4 { void* pad0; Struct_ov031_02211d54* unknown_4_; };
extern Struct_ov031_0224e5b4_4 data_ov031_0224e5b4;

extern "C" void func_ov031_02211ca0(void);
extern "C" int func_ov031_02211f24(void);
extern "C" void func_ov031_022130e8(int, int, int, int, int);

// USA: func_ov031_02211d54
extern "C" ARM void func_ov031_02211d54(int a, int b, int c, int d, int e) {
	func_ov031_02211ca0();
	if (data_ov031_0224e5b4.unknown_4_ != NULL) {
		data_ov031_0224e5b4.unknown_4_->fieldc = 1;
	}
	if (func_ov031_02211f24() == 2) {
		func_ov031_022130e8(a, b, c, d, e);
	}
}
