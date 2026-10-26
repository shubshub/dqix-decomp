#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" void func_ov031_022258b4(void);
extern "C" int func_ov031_02236878(int index);
extern unsigned char* data_ov031_02290c98;
extern "C" void func_ov031_02225c38(int v);
extern "C" void func_ov031_02225c4c(unsigned char v);
extern "C" void func_ov031_02225c60(unsigned char v);
extern "C" int func_ov031_0222dd70(int arg0);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222da30(void);

// USA: func_ov031_0222d9a4
extern "C" ARM void func_ov031_0222d9a4(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_022258b4();
	func_ov031_02236878(0x14);
	if (data_ov031_02290c98[0x14] == 0) {
		func_ov031_02225c38(0);
		func_ov031_02225c60(0);
	} else {
		if (func_ov031_0222dd70(0x1a) != 0) {
			func_ov031_02225c4c(0);
		}
		func_ov031_02225c60(0);
	}
	func_ov031_022274c0((int)func_ov031_0222da30);
}
