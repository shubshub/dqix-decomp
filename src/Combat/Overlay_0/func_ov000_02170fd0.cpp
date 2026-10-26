#include <globaldefs.h>

extern "C" void func_ov000_0217f518(void*);
extern "C" void func_ov000_0217636c(void*, int);

struct Struct_ov000_02170fd0 {
	unsigned char pad0[0x38];
	int unknown_38_;
};

// USA: func_ov000_02170fd0
extern "C" ARM void func_ov000_02170fd0(struct Struct_ov000_02170fd0* obj, int b) {
	func_ov000_0217f518(obj);
	if (obj->unknown_38_ != 0) {
		func_ov000_0217636c(obj, b);
	}
}
