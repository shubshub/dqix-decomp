#include <globaldefs.h>

extern "C" unsigned char func_ov031_0223c054(int mode);
extern "C" int func_ov031_02223568(void* obj);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02231674(void);

// USA: func_ov031_02231648
extern "C" ARM void func_ov031_02231648(void) {
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568((void*)1);
	func_ov031_022274c0((int)func_ov031_02231674);
}
