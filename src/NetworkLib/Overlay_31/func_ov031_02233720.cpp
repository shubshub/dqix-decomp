#include <globaldefs.h>

struct Struct_ov031_02290cc8_4 {
	unsigned char pad[2];
	unsigned char field2;
};

extern Struct_ov031_02290cc8_4 data_ov031_02290cc8;

extern "C" int func_ov031_0223c054(int arg);
extern "C" int func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_02233784(void);
extern "C" ARM int func_ov031_02222ddc(void);
extern "C" ARM void func_ov031_022274c0(int v);

// USA: func_ov031_02233720
extern "C" ARM void func_ov031_02233720(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (data_ov031_02290cc8.field2 != 0) {
		func_ov031_02222ddc();
	}
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x14, 8);
	func_ov031_022274c0((int)func_ov031_02233784);
}
