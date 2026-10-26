#include <globaldefs.h>

extern "C" void func_ov017_021b65bc(char* obj);

// USA: func_ov017_021a3b00
extern "C" ARM void func_ov017_021a3b00(int unused, char* obj) {
	if (obj == NULL) return;
	if ((unsigned char)obj[1] != 0) goto ret1;
	if ((signed char)obj[0] != 0x16) goto ret2;
	func_ov017_021b65bc(obj);
	return;
ret1:
	return;
ret2:
	return;
}
