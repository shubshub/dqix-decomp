#include <globaldefs.h>

extern "C" void func_ov031_0223d8a0(void);
extern "C" void func_ov031_0223bf48(void* p, int a);

struct Struct_ov031_0223dcf4 { unsigned char pad[0x19c]; void* unknown_19c_; };
extern struct Struct_ov031_0223dcf4* data_ov031_02290d64;

// USA: func_ov031_0223dcf4
extern "C" ARM void func_ov031_0223dcf4(int a) {
	int idx = 0;
	func_ov031_0223d8a0();
	if ((unsigned int)a >= (unsigned int)&data_ov031_02290d64[1]) {
		idx = 1;
	}
	func_ov031_0223bf48(data_ov031_02290d64[idx].unknown_19c_, a);
}
