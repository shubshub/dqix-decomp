#include <globaldefs.h>

extern "C" int func_ov017_021d4ce4(void* a, int b);
extern "C" void func_ov001_0215a9b4(void* a);
extern int data_ov001_02165828;
extern int data_ov001_0216580c;

// USA: func_ov001_02153948
extern "C" ARM int func_ov001_02153948(unsigned short arg) {
	int r4 = func_ov017_021d4ce4(&data_ov001_02165828, arg);
	if (r4 == -1) {
		return 0;
	}
	if (r4 != 0) {
		data_ov001_0216580c = arg;
		func_ov001_0215a9b4(&data_ov001_0216580c);
	}
	return r4;
}
