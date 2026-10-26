#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cdccc(int a, int b, void* c);

struct Obj021cdd30 {
	unsigned char pad0[4];
	unsigned short field4;
};

// USA: func_ov017_021cdd30
ARM void Something_021cdd30(int unused1, Obj021cdd30* s, int unused2, int unused3, struct SearchStruct0202c1a4* obj) {
	unsigned int t = (unsigned int)s->field4 << 30;
	int lo2 = (int)(t >> 30);
	if (LinkSession_GetOwnSlot(obj) != (int)(t >> 30)) return;
	func_ov017_021cdccc(lo2, (int)(((unsigned int)s->field4 << 16) >> 18), (char*)s + 6);
}
