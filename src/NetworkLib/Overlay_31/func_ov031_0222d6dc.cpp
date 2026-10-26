#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222ce24(void);

struct Struct_ov031_0222d6dc { unsigned char pad[4]; int *field4; };
extern Struct_ov031_0222d6dc *data_ov031_02290c94;

// USA: func_ov031_0222d6dc
extern "C" ARM void func_ov031_0222d6dc(void) {
	if (func_ov031_02237eb0() != 0) return;
	int *p = data_ov031_02290c94->field4;
	*p = *p & 0xc1fffcff;
	func_ov031_022274c0((int)func_ov031_0222ce24);
}
