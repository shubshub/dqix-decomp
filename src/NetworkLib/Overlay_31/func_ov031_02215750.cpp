#include <globaldefs.h>

extern "C" void func_ov031_022157f8(int a, void* buf);
extern "C" void func_ov031_022158fc(void* buf, void* b);

// USA: func_ov031_02215750
extern "C" ARM void func_ov031_02215750(int a, void* b) {
	unsigned int buf[6];
	func_ov031_022157f8(a, buf);
	func_ov031_022158fc(buf, b);
}
