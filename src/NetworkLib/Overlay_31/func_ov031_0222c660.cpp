#include <globaldefs.h>

struct Struct_ov031_0222c660 {
	unsigned char pad0[0x10];
	int* upper[5];
	int* lower[5];
	unsigned char pad1[0x51 - 0x38];
	unsigned char unknown_51_;
	unsigned char pad2[0x56 - 0x52];
	unsigned char unknown_56_;
};
struct Struct_ov031_02290c8c_13 { unsigned char pad[2]; unsigned short field2; Struct_ov031_0222c660* field4; };
extern Struct_ov031_02290c8c_13 data_ov031_02290c8c;

extern "C" int FastIntModulus(int arg0, int arg1);

// USA: func_ov031_0222c660
extern "C" ARM void func_ov031_0222c660(void) {
	int base = 0x36 - FastIntModulus(data_ov031_02290c8c.field2, 0x1c);
	int count = data_ov031_02290c8c.field4->unknown_51_;
	if (count > 5) count = 5;
	for (int idx = 0; idx < count; idx++) {
		int* upper = data_ov031_02290c8c.field4->upper[idx];
		*upper = (*upper & 0xfe00ff00) | ((base - 2) & 0xff) | 0xb30000;
		int* lower = data_ov031_02290c8c.field4->lower[idx];
		*lower = (*lower & 0xfe00ff00) | ((base + 1) & 0xff) | 0xd20000;
		base += 0x1c;
	}
	data_ov031_02290c8c.field4->unknown_56_ = 1;
}
