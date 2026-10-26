#include <globaldefs.h>

struct Struct_ov031_0224e1c0_4 {
	char pad[8];
	int field8;
};

extern Struct_ov031_0224e1c0_4 data_ov031_0224e1c0;

// USA: func_ov031_02205000
extern "C" ARM void func_ov031_02205000(void) {
	data_ov031_0224e1c0.field8 |= 0x2;
}
