#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" void func_ov017_02190264(unsigned char* obj, unsigned char b);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_ov017_021cc6c4 {
	unsigned char pad0[4];
	unsigned char count;
	unsigned char bytes[1];
};

// USA: func_ov017_021cc6c4
extern "C" ARM void func_ov017_021cc6c4(int unused0, Struct_ov017_021cc6c4* src, int arg2, unsigned char* obj, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0xc1};
#else
 enum {regionalOffset0=0x2e1};
#endif
	int var0 = 0;
	for (int i = 0; i < src->count; i++) {
		unsigned char b = src->bytes[i];
		func_ov017_02190264(obj, b);
		if (b == 0) var0 = 1;
	}
	if (!var0) return;
	if (LinkSession_GetOwnSlot(search) != 0) {
		obj[0x4000 + regionalOffset0] = 1;
	}
}
