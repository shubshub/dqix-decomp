#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d24a8 {
	unsigned char field0;
	unsigned char pad0[3];
	int field4;
};

struct Struct_ov017_021d24a8_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021d24a8 payload;
	unsigned char pad1[8];
};

// USA: func_ov017_021d24a8
extern "C" ARM void func_ov017_021d24a8(int a) {
	void* p = LinkMessageQueue_GetInstance();

	Struct_ov017_021d24a8_2 buf;
	Struct_ov017_021d24a8* var2 = &buf.payload;
	var2->field0 = a;
	buf.tag = 0x1e;
	unsigned short* q = Zone3D_GetInstance();
	var2->field4 = *q;
	func_0205e330(p, &buf, 0);
}
