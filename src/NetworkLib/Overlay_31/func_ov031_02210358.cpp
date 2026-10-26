#include <globaldefs.h>

extern "C" void func_ov031_02211864(int a, int b);
extern "C" void func_ov031_0221038c(int v);
extern void* data_ov031_0224e588;

// USA: func_ov031_02210358
extern "C" ARM void func_ov031_02210358(int a, int b) {
	void* p = data_ov031_0224e588;
	if (p != NULL) {
		if (*(int*)((char*)p + 4) == 2) return;
	}
	func_ov031_02211864(a, b);
	func_ov031_0221038c(2);
}
