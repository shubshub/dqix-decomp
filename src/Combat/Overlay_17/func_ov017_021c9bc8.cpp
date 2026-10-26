#include <globaldefs.h>

struct Entry0207d9bc;
struct Struct_0207da94;
struct Struct0216377c;

extern "C" void* func_0207d78c(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" void func_0207da94(struct Struct_0207da94* list, int idx);
extern "C" int func_0207db58(struct Entry0207d9bc* arr, unsigned short key, char val);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
extern "C" void func_ov000_0216377c(struct Struct0216377c* obj, unsigned char val);

struct Struct_ov017_021c9bc8 { char pad[4]; unsigned short f4; unsigned short unknown_6_; };

// USA: func_ov017_021c9bc8
extern "C" ARM void func_ov017_021c9bc8(char a0, struct Struct_ov017_021c9bc8* a1, int a2, char* a3, void* a4) {
#if defined(jpn)
 enum {regionalOffset0=0x3508};
#else
 enum {regionalOffset0=0x3718};
#endif
	void* table = func_0207d78c();
	unsigned int f4 = a1->f4;
	unsigned short var2 = a1->unknown_6_;
	if (LinkSession_IsHostOrSolo(a4)) {
		func_0207da94((struct Struct_0207da94*)table, var2 & 0xff);
		func_0207db58((struct Entry0207d9bc*)table, (unsigned short)f4, a0);
		return;
	}
	if (a0 != 0) return;
	struct Struct0216377c* obj = *(struct Struct0216377c**)(a3 + regionalOffset0);
	void* p1 = func_ov017_021b8478(obj);
	int p2 = func_ov017_021b8468(obj);
	if (p1 == 0 || p2 == 0) return;
	if (*(unsigned short*)((char*)p1 + 8) != f4) return;
	typedef void (*Type_ov017_021c9bc8)(struct Struct0216377c*, unsigned short);
	((Type_ov017_021c9bc8)func_ov000_0216377c)((struct Struct0216377c*)p2, var2);
}
