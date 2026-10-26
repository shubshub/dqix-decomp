#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021c8bac_14104 = 0x3508 };
#else
enum { Enum_ov017_021c8bac_14104 = 0x3718 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_02160fa8(void* work, int mask);

struct Struct_ov017_021c8bac {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Struct_ov017_021c8bac_2 {
	unsigned char pad0[4];
	unsigned short field4;
};

// USA: func_ov017_021c8bac
extern "C" ARM void func_ov017_021c8bac(int unused0, Struct_ov017_021c8bac_2* src, int arg2, unsigned char* obj) {
	unsigned char* h = *(unsigned char**)(obj + Enum_ov017_021c8bac_14104);
	if (h[2] == 0) return;
	Struct_ov017_021c8bac* r = (Struct_ov017_021c8bac*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	void* work = func_ov017_021b8468(h);
	if (!work) return;
	func_ov000_02160fa8(work, 0x2000000);
}
