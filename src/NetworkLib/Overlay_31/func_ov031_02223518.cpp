#include <globaldefs.h>

extern "C" void func_ov031_022274e4(int *a, int *b);
extern "C" int func_ov031_0223690c(void *obj);
extern "C" int func_ov031_02236ea0(void *obj);

// USA: func_ov031_02223518
extern "C" ARM int func_ov031_02223518(void *obj) {
	int a;
	func_ov031_022274e4(&a, 0);
	if (a == 1) return func_ov031_0223690c(obj);
	if (a != 2) return a;
	return func_ov031_02236ea0(obj);
}
