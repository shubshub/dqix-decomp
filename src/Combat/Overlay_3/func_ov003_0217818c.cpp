#include <globaldefs.h>
#if defined(jpn)
enum { kRegion89c = 0x818 };
#else
enum { kRegion89c = 0x89c };
#endif

extern "C" int func_02080b40(void* obj, int id);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_02080798(void* obj, int id, int value);

struct Struct_ov003_021767ec {
	char pad0[8];
	unsigned int unknown_8_0_ : 12;
	unsigned int type2 : 2;
	unsigned int unknown_9_6_ : 18;
};

// USA: func_ov003_0217818c
extern "C" ARM void func_ov003_0217818c(char* self, struct Struct_ov003_021767ec* arg1, int id, int value) {
	void* var0 = *(void**)(self + kRegion89c);
	unsigned char flag = 1;
	if (arg1 != 0) {
		if (arg1->type2 == 0) {
			flag = 0;
		}
		flag &= 0xff;
	}
	if (flag) {
		func_02080b40(var0, id);
		func_0208103c(var0, value, 0x48);
#if !defined(jpn)
#if !defined(jpn)
		func_02080798(var0, value, 1);
#endif
#endif
	} else {
		func_02080b2c(var0, id);
		func_0208103c(var0, value, 0x46);
#if !defined(jpn)
#if !defined(jpn)
		func_02080798(var0, value, 1);
#endif
#endif
	}
}
