#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" unsigned short func_ov017_021b8480(void* obj);
extern "C" void func_ov017_021cbf18(unsigned char a, unsigned short b);

struct Struct_ov017_021cbf54 {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Struct_ov017_021cbf54_2 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char pad1;
	unsigned short field6;
};

// USA: func_ov017_021cbf54
extern "C" ARM void func_ov017_021cbf54(int unused0, Struct_ov017_021cbf54_2* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
	Struct_ov017_021cbf54* r = (Struct_ov017_021cbf54*)func_ov017_021b8478(h);
	if (r->field8 != src->field6) return;
	if (src->field4 == 0) {
		if (func_ov017_021b8480(h) == 2) return;
		func_ov017_021cbf18(1, src->field6);
	} else {
		if (src->field4 == 1) {
			*(unsigned char*)(h + 0x6c7) = 2;
		}
	}
}
