#include <globaldefs.h>

struct SearchStruct0202c1a4 {
	char pad[0x1038];
	signed char arr[16];
};

extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d1dc0 {
	short a;
	short b;
	short c;
	short d;
	short scaledX;
	short scaledY;
	short unknown_c_;
};

struct Struct_ov017_021d1dc0_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021d1dc0 sub;
	unsigned char pad1[2];
};

// USA: func_ov017_021d1dc0
extern "C" ARM void func_ov017_021d1dc0(unsigned short a, int b, int* vec3, int c, int d) {
	if (!LinkSession_IsActive(LinkSession_GetInstance())) return;
	if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance()) != 0) return;
	void* p = LinkMessageQueue_GetInstance();

	struct Struct_ov017_021d1dc0_2 buf;
	buf.tag = 0xb5;
	buf.sub.a = a;
	buf.sub.b = b;
	buf.sub.c = c;
	buf.sub.d = (short)d;
	buf.sub.scaledX = (short)(vec3[0] >> 7);
	buf.sub.scaledY = (short)(vec3[1] >> 7);
	buf.sub.unknown_c_ = (short)(vec3[2] >> 7);
	func_0205e330(p, &buf, 0);
}
