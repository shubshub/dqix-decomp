#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02165b4c func_ov004_021663dc
#endif

extern "C" void func_ov011_021848a0(int a1, int a2);

// USA: func_ov004_02165b4c
extern "C" ARM int func_ov004_02165b4c(int a1) {
	func_ov011_021848a0(a1, 0x68);
	return 0;
}
