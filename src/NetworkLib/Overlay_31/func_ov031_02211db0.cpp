#include <globaldefs.h>

struct Struct_ov031_02211db0 {
	int field0;
	unsigned short field4;
	char pad[0xc - 0x6];
	unsigned char unknown_c_;
};

struct Struct_ov031_0224e5b4_5 {
	char pad4[4];
	Struct_ov031_02211db0* field4;
};

extern Struct_ov031_0224e5b4_5 data_ov031_0224e5b4;
extern "C" void func_ov031_02211f24(void);

// USA: func_ov031_02211db0
extern "C" ARM int func_ov031_02211db0(void) {
	Struct_ov031_02211db0* q = data_ov031_0224e5b4.field4;
	if (q == NULL) return 0;
	if (q->field0 != 0) {
		q->field4 = 3;
		func_ov031_02211f24();
		q = data_ov031_0224e5b4.field4;
		return q->unknown_c_ != 0;
	} else {
		return 0;
	}
}
