#include <globaldefs.h>


struct Struct_ov031_022358b4 { unsigned short field0; unsigned short field2; unsigned char pad4[4]; unsigned short field8; };

extern "C" void func_ov031_02235a44(struct Struct_ov031_022358b4* a);
extern "C" int func_ov031_022358b4(void);
extern "C" void HaltSystem(void);

extern char* data_ov031_02290cf8;

// USA: func_ov031_022359e0
extern "C" ARM void func_ov031_022359e0(struct Struct_ov031_022358b4* obj) {
	if (obj->field2 != 0) {
		return;
	}
	unsigned char b = *(unsigned char*)(data_ov031_02290cf8 + 0x1e5c);
	if (b != 0 || obj->field0 != 0x26) {
		return;
	}
	if (obj->field8 == 4) {
		goto case4;
	}
	if (obj->field8 != 5) {
		goto def;
	}
	func_ov031_02235a44(obj);
	func_ov031_022358b4();
	return;
case4:
	func_ov031_022358b4();
	return;
def:
	HaltSystem();
}
