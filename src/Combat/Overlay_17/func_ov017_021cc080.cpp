#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" int func_ov000_02163d94(void* p);

struct Struct_ov017_021cc080 { unsigned char pad[4]; unsigned short field4; };
struct Struct_ov017_021cc080_2 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cc080
extern "C" ARM void func_ov017_021cc080(int unused0, Struct_ov017_021cc080* src, int arg2, unsigned char* obj) {
	obj += 0x3000;
	void* work = *(void**)(obj +
#if defined(jpn)
        0x508
#else
        0x718
#endif
);
	Struct_ov017_021cc080_2* r = (Struct_ov017_021cc080_2*)func_ov017_021b8478(work);
	void* r2 = func_ov017_021b8468(work);
	if (!r) {
		return;
	}
	if (r->field8 != src->field4) {
		return;
	}
	if (!r2) {
		return;
	}
	func_ov000_02163d94(r2);
}
