#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_020891cc(void* obj);

struct Struct_ov017_021ca358 {
	unsigned char pad0[8];
	unsigned short field8;
	unsigned char pad1[0x30 - 0xa];
	int unknown_30_;
};

struct Struct_ov017_021ca358_2 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
};

// USA: func_ov017_021ca358
extern "C" ARM void func_ov017_021ca358(int unused0, Struct_ov017_021ca358_2* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* h = *(void**)(obj + 0x3000 + regionalOffset0);
	Struct_ov017_021ca358* r = (Struct_ov017_021ca358*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	if (src->field6 != 0) {
		if (r->unknown_30_ == 0) return;
	}
	for (int i = 0; i < 8; i++) {
		func_020891cc((unsigned char*)r + 0x158 + i * 0xa4);
	}
}
