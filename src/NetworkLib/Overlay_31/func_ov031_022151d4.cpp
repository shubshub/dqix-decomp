#include <globaldefs.h>

extern "C" int func_ov031_0220d540(void);
extern "C" char* func_ov031_022133f8(unsigned int flags);
extern "C" int func_ov031_02214520(int);
extern "C" int func_ov031_0220cae0(void* local, void (*fn)(void));
extern "C" void func_ov031_02213c10(void);
extern "C" void func_ov031_022134cc(int v);

struct Struct_ov031_022151d4 { unsigned int f0, f4, f8, unknown_c_; };

// USA: func_ov031_022151d4
extern "C" ARM int func_ov031_022151d4(void) {
	int a = func_ov031_0220d540();
	char* ptr = func_ov031_022133f8(0x10);
	if (a == 1) {
		Struct_ov031_022151d4 local;
		local.f0 = (unsigned char)ptr[0xd0a];
		local.f4 = 0;
		local.f8 = 0;
		local.unknown_c_ = 0;
		func_ov031_02214520(0);
		int r = func_ov031_0220cae0(&local, func_ov031_02213c10);
		if (r == 1 || r >= 4) {
			func_ov031_022134cc(1);
			return 0x11;
		}
	} else {
		return 1;
	}
	return 2;
}
