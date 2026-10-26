#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_022238cc(void);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223b710(int);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_02232508(void);
extern "C" void func_ov031_0222905c(void);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_022274c0(int);

struct Struct_ov031_02290c50 {
	unsigned char field0;
	unsigned char pad[3];
	int field4;
};

extern Struct_ov031_02290c50 data_ov031_02290c50;

// USA: func_ov031_02228444
extern "C" ARM void func_ov031_02228444(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;

	func_ov031_022238cc();
	func_ov031_02223440();
	func_ov031_0223b710(data_ov031_02290c50.field4);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x14);

	unsigned char state = data_ov031_02290c50.field0;
	if (state == 0) goto case0;
	if (state == 1) goto case1;
	return;
case0:
	func_ov031_022274d0(1, 0);
	func_ov031_022274c0((int)func_ov031_02232508);
	return;
case1:
	func_ov031_022274d0(0, 0);
	func_ov031_022274c0((int)func_ov031_0222905c);
	return;
}
