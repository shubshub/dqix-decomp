#include <globaldefs.h>

struct Struct_ov031_0223d5ac {
	unsigned char pad[0x28];
	unsigned short unknown_28_;
	unsigned short max;
	unsigned char pad2[0xc];
	unsigned char unknown_38_0_:1, flag1:1, flag2:1, unknown_38_3_:1, flag4:1, flag5:1, unknown_38_6_:1, flag7:1;
};
struct Struct_ov031_02290d40_9 { unsigned char pad[4]; struct Struct_ov031_0223d5ac* inner; };
extern struct Struct_ov031_02290d40_9 data_ov031_02290d40;

struct Struct_ov031_0223d5ac_2 { unsigned short f0, f1, f2, f3; };

// USA: func_ov031_0223d5ac
extern "C" ARM int func_ov031_0223d5ac(struct Struct_ov031_0223d5ac_2* p) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) return 0;
	struct Struct_ov031_0223d5ac* in = data_ov031_02290d40.inner;
	if (!in->unknown_38_3_) return 0;
	unsigned short var2 = in->unknown_28_;
	if (p->f0 > var2) return 0;
	if (p->f2 < var2) return 0;
	unsigned short max = in->max;
	if (p->f1 > max) return 0;
	return (p->f3 >= max) ? 1 : 0;
}
