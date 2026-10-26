#include <globaldefs.h>

extern "C" int func_020d68d0(void* p);
extern "C" void func_ov031_022393e4(int v);

struct Struct_ov031_02290d18_13 { unsigned char pad[4]; char* inner; };
extern struct Struct_ov031_02290d18_13 data_ov031_02290d18;

// USA: func_ov031_02239924
extern "C" ARM int func_ov031_02239924(void) {
	void* p = data_ov031_02290d18.inner + 0x1e00;
	int r = func_020d68d0(p);
	if (r == 2) {
		return 1;
	}
	func_ov031_022393e4(r);
	return 0;
}
