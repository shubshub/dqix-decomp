#include <globaldefs.h>

struct Struct_ov031_02290d18_14 { void (*fn)(int, void*); };
extern struct Struct_ov031_02290d18_14 data_ov031_02290d18;
extern int data_ov031_0224c3f4;

extern "C" int func_ov031_022399d8(void);
extern "C" void func_ov031_022393e4(int v);
extern "C" int func_ov031_0223a358(void);

// USA: func_ov031_02239984
extern "C" ARM void func_ov031_02239984(short* p) {
	unsigned short v = *(unsigned short*)((char*)p + 2);
	if (v != 0) {
		func_ov031_022393e4(v);
		func_ov031_0223a358();
		return;
	}
	if (func_ov031_022399d8() != 0) {
		return;
	}
	if (data_ov031_02290d18.fn != 0) {
		data_ov031_02290d18.fn(0x8000000, &data_ov031_0224c3f4);
	}
	func_ov031_0223a358();
}
