#include <globaldefs.h>

struct Struct_ov031_02223f6c {
	unsigned char pad[0x114];
	int unknown_114_;
	int unknown_118_;
};

extern Struct_ov031_02223f6c* data_ov031_02250bfc;

extern "C" void func_ov031_0223ba20(int a);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225580(void);

// USA: func_ov031_02223f6c
extern "C" ARM void func_ov031_02223f6c(void) {
	func_ov031_0223ba20(data_ov031_02250bfc->unknown_114_);
	func_ov031_0223e2b8((void*)data_ov031_02250bfc->unknown_118_, (int)func_ov031_02225580);
}
