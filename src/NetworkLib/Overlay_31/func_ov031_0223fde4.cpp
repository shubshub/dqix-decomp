#include <globaldefs.h>

struct Struct_ov031_02290fbc_2 {
	int field0;
	unsigned char pad[8];
	int (*fieldC)(int);
	unsigned char pad2[8];
	int field18;
};

extern "C" void func_ov031_02240f74(void);
extern "C" void func_ov031_0224030c(void);
extern "C" void func_ov031_022403b0(void);
extern struct Struct_ov031_02290fbc_2 data_ov031_02290fbc;

// USA: func_ov031_0223fde4
extern "C" ARM void func_ov031_0223fde4(void (*callback)(void)) {
	func_ov031_02240f74();
	func_ov031_022403b0();
	data_ov031_02290fbc.fieldC(data_ov031_02290fbc.field18);
	func_ov031_0224030c();
	data_ov031_02290fbc.field0 = 0;
	callback();
}
