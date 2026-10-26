#include <globaldefs.h>

struct Struct_ov031_0224e6a0_4 {
	unsigned short field0;
	unsigned short pad2;
	int field4;
};

extern Struct_ov031_0224e6a0_4 data_ov031_0224e6a0;

// USA: func_ov031_0221b8b4
extern "C" ARM unsigned int func_ov031_0221b8b4(int unused, int val, int cond) {
	data_ov031_0224e6a0.field0 = (unsigned char)val;
	data_ov031_0224e6a0.field4 = 1;
	if (cond != 0) {
		data_ov031_0224e6a0.field0 = 0xff;
	}
	return data_ov031_0224e6a0.field0;
}
