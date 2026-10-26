#include <globaldefs.h>

struct Struct_ov031_02240f74 { unsigned char pad4[4]; int field4; };
struct Struct_ov031_02240f74_2 { unsigned char pad0[0xc]; Struct_ov031_02240f74* volatile sub; int unknown_10_; };
extern Struct_ov031_02240f74_2* data_ov031_02290fcc;

extern "C" ARM void* func_ov031_02240310(void);
extern "C" ARM int func_ov031_02241518(int a, int b);
extern "C" ARM void func_ov031_022402b0(void);
extern "C" ARM void func_ov031_02240324(void);

// USA: func_ov031_02240f74
extern "C" ARM void func_ov031_02240f74(void) {
	func_ov031_02240310();
	if (data_ov031_02290fcc != NULL) {
		if (data_ov031_02290fcc->sub->field4 == 0) {
			data_ov031_02290fcc->sub->field4 = 1;
			func_ov031_02241518((int)data_ov031_02290fcc->sub, data_ov031_02290fcc->unknown_10_);
		}
	}
	func_ov031_022402b0();
	func_ov031_02240324();
}
