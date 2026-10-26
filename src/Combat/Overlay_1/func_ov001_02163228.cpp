#include <globaldefs.h>

extern "C" int func_ov028_021d9748(void);
extern "C" void func_ov017_021d6134(int a, int b);

// USA: func_ov001_02163228
extern "C" ARM int func_ov001_02163228(int a) {
	int b = func_ov028_021d9748();
	func_ov017_021d6134(a, b);
	return 1;
}
