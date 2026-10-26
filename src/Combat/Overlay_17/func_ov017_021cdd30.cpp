#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cdccc(int a, int b, void* c);

struct Struct_ov017_021cdd30 {
	unsigned char pad0[4];
	unsigned short field4;
};

// USA: func_ov017_021cdd30
extern "C" ARM void func_ov017_021cdd30(int unused1, Struct_ov017_021cdd30* s, int arg2, int arg3, struct SearchStruct0202c1a4* obj) {
	unsigned int t = (unsigned int)s->field4 << 30;
	int var1 = (int)(t >> 30);
	if (LinkSession_GetOwnSlot(obj) != (int)(t >> 30)) return;
	func_ov017_021cdccc(var1, (int)(((unsigned int)s->field4 << 16) >> 18), (char*)s + 6);
}
