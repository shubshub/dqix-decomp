#include <globaldefs.h>

extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* func_0207d78c(void);

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
extern "C" void func_0207da7c(Entry0207d9bc* arr, unsigned short key);

struct Struct_ov017_021c5e28 {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char id;
	unsigned char pad1;
	short val;
	unsigned char pad3[0xc];
};

// USA: func_ov017_021c5e28
extern "C" ARM void func_ov017_021c5e28(int id, int val) {
	LinkSession_GetInstance();
	if (LinkSession_IsHostOrSolo()) {
		void* p = LinkMessageQueue_GetInstance();
		struct Struct_ov017_021c5e28 buf;
		buf.tag = 0x3e;
		buf.id = (unsigned char)id;
		buf.val = val;
		func_0205e330(p, &buf, 0);
		Entry0207d9bc* arr = (Entry0207d9bc*)func_0207d78c();
		func_0207da7c(arr, (unsigned short)val);
	}
}
