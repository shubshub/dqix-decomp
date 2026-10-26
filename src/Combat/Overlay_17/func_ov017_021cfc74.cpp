#include <globaldefs.h>

extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cfc74 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char field4;
	unsigned char pad1[15];
};

// USA: func_ov017_021cfc74
extern "C" ARM void func_ov017_021cfc74(unsigned char a) {
	LinkSession_GetInstance();
	if (LinkSession_IsGuest() == 0) {
		Struct_ov017_021cfc74 buf;
		void* p = LinkMessageQueue_GetInstance();
		buf.tag = 0xa2;
		buf.field4 = a;
		func_0205e330(p, &buf, 0);
	}
}
