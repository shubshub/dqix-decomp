#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" int func_ov031_02222e54(void);
extern "C" void func_ov031_022238cc(void);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222750c(int, int);
extern "C" void func_ov031_02230ef0(unsigned char);

extern "C" void func_ov031_0223b710(int);

struct Struct_ov031_02290cc8_5 { char pad0; signed char field1; unsigned char field2; char pad3; int field4; };
extern Struct_ov031_02290cc8_5 data_ov031_02290cc8;

extern "C" void func_ov031_02232508(void);
extern "C" void func_ov031_02232024(void);
extern "C" void func_ov031_0222aeb4(void);
extern "C" void func_ov031_02231bb0(void);
extern "C" void func_ov031_0222ea24(void);

// USA: func_ov031_02233784
extern "C" ARM void func_ov031_02233784(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	if (func_ov031_02222e54() == 0) return;

	func_ov031_022238cc();
	func_ov031_02223440();
	func_ov031_0223b710(data_ov031_02290cc8.field4);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x14);

	if (data_ov031_02290cc8.field2 == 0) {
		func_ov031_022274d0(2, 0);
		func_ov031_022274c0((int)func_ov031_02232508);
		return;
	}
	switch (data_ov031_02290cc8.field1) {
	case 0:
		func_ov031_022274d0(2, 1);
		func_ov031_022274c0((int)func_ov031_02232024);
		return;
	case 1:
		func_ov031_022274d0(2, 1);
		func_ov031_022274c0((int)func_ov031_0222aeb4);
		return;
	case 2:
		func_ov031_022274d0(2, 1);
		func_ov031_022274c0((int)func_ov031_02231bb0);
		return;
	case 3:
		func_ov031_022274d0(2, 0);
		func_ov031_0222750c(0, 0);
		func_ov031_02230ef0(1);
		func_ov031_022274c0((int)func_ov031_0222ea24);
		return;
	}
}
