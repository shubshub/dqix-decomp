#if defined(jpn)
#define R(j,u) (j)
#define func_ov004_02167b78 func_ov004_02168074
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov004_0216794c(short* a, short* b, short* c, unsigned char* d, int* e);
extern "C" void func_ov004_02167b78(void* a, int b);
extern "C" void func_ov004_02167adc(void* a);
extern "C" void func_ov011_021848a0(void* a, int b);

// USA: func_ov004_02167eb0
extern "C" ARM int func_ov004_02167eb0(void* a) {
	short outA, var1, var2;
	unsigned char var3;
	int var4;
	func_ov004_0216794c(&outA, &var1, &var2, &var3, &var4);
	func_ov004_02167b78(a, 0);
	func_ov004_02167adc(a);
	if (var3 != 0) {
		func_ov011_021848a0(a, 0x28);
	} else {
		func_ov011_021848a0(a, 0x33);
	}
	return 0;
}
