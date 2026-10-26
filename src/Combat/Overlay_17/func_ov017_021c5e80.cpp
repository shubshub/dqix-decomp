#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_ov017_021b8b6c(char* p);
extern "C" void func_ov017_021a23b0(void* self, int val);

struct Struct_ov017_021c5e80 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char pad1;
	unsigned short field6;
};

// USA: func_ov017_021c5e80
extern "C" ARM void func_ov017_021c5e80(int unused0, Struct_ov017_021c5e80* src, int arg2, unsigned char* base, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char field4 = src->field4;
	unsigned short field6;
	void* var2 = *(void**)(base + 0x3000 + regionalOffset0);
	field6 = src->field6;
	signed char val = LinkSession_GetOwnSlot(search);
	if (field4 != val) {
		if (*((unsigned char*)var2 + 2) == 0) return;
		void* g = func_ov017_021b8478(var2);
		if (!g) return;
		if (*(unsigned short*)((char*)g + 8) != field6) return;
		func_ov017_021b8b6c((char*)var2);
		func_ov017_021a23b0(base, field6);
		return;
	}
	func_ov017_021b8b6c((char*)var2);
	func_ov017_021a23b0(base, field6);
}
