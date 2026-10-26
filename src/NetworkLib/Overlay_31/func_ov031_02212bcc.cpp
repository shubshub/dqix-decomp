#include <globaldefs.h>

struct Struct_ov031_02212bcc { unsigned char pad0[4]; void* field4; unsigned char pad1[0x48 - 8]; int field48; };
struct Struct_ov031_0224e5c0 { Struct_ov031_02212bcc* field0; };
extern Struct_ov031_0224e5c0 data_ov031_0224e5c0;
extern "C" void func_ov031_022128b8(void);
extern "C" int func_ov031_0223e8ac(void* arg);

// USA: func_ov031_02212bcc
extern "C" ARM int func_ov031_02212bcc(void* callback) {
	Struct_ov031_02212bcc* p = data_ov031_0224e5c0.field0;
	if (p == NULL) return 0;
	p->field4 = callback;
	if (data_ov031_0224e5c0.field0->field48 == 0) {
		func_ov031_022128b8();
	} else {
		func_ov031_0223e8ac((void*)func_ov031_022128b8);
	}
	return 1;
}
