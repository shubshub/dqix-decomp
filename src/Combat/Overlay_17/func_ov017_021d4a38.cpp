#include <globaldefs.h>

struct Struct_ov017_021d4a38_2 { int a; int b; };
extern "C" void func_ov017_021d4a64(Struct_ov017_021d4a38_2* dst, Struct_ov017_021d4a38_2* src);

struct Struct_ov017_021d4a38 { unsigned char pad[0x14]; Struct_ov017_021d4a38_2* cursor; };

// USA: func_ov017_021d4a38
extern "C" ARM void func_ov017_021d4a38(Struct_ov017_021d4a38* obj, Struct_ov017_021d4a38_2 arg) {
	Struct_ov017_021d4a38_2* e = obj->cursor;
	obj->cursor = e + 1;
	func_ov017_021d4a64(e, &arg);
}
