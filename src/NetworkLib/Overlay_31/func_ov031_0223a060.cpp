#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_022393e4(int v);
extern "C" ARM int func_ov031_0223a0ac(short* p);
extern "C" int func_020d4f7c(int a, int b, int c);

struct Struct_ov031_02290d18_22 { void* unk0; void* field4; };
extern struct Struct_ov031_02290d18_22 data_ov031_02290d18;

// USA: func_ov031_0223a060
extern "C" ARM int func_ov031_0223a060(void) {
	func_ov031_02239368(3);
	int r = func_020d4f7c((int)((char*)data_ov031_02290d18.field4 + 0x80), (int)func_ov031_0223a0ac, 2);
	if (r == 2) {
		return 1;
	}
	func_ov031_022393e4(r);
	func_ov031_02239368(0xa);
	return 0;
}
