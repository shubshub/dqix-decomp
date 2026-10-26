#include <globaldefs.h>

extern "C" int func_ov024_021fe698(char* obj, int idx);
extern "C" void func_ov024_021fdf04(void* obj, int idx);

// USA: func_ov024_021fc254
extern "C" ARM void func_ov024_021fc254(char* obj) {
	if (func_ov024_021fe698(obj, 1)) {
		func_ov024_021fdf04(obj, 5);
	}
}
