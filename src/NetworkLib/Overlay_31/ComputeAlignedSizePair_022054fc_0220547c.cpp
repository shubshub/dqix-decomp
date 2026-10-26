#include <globaldefs.h>

extern "C" unsigned int func_ov031_022070bc(unsigned int size);

struct Struct_ov031_022054fc {
	unsigned short field0;
	unsigned char field2;
	unsigned char unknown_3_;
};
extern "C" ARM int func_ov031_022054fc(Struct_ov031_022054fc* p);

struct Struct_ov031_0220547c {
	char pad0[0x2];
	unsigned short field2;
	char pad4[0x2];
	unsigned short field6;
	unsigned short field8;
	unsigned short fieldA;
	unsigned short fieldC;
	char unknown_e_[0x2];
	Struct_ov031_022054fc unknown_10_;
	Struct_ov031_022054fc unknown_14_;
};

// USA: func_ov031_0220547c
extern "C" ARM int func_ov031_0220547c(Struct_ov031_0220547c* obj) {
	int total = 0x80;
	if (obj->field2 != 0) {
		total += 0x114;
		total += func_ov031_022070bc(obj->field2);
		total += func_ov031_022070bc(obj->field8);
		total += func_ov031_022054fc(&obj->unknown_10_);
	}
	if (obj->field6 != 0) {
		total += 0x110;
		total += func_ov031_022070bc(obj->field6);
		total += func_ov031_022070bc(obj->fieldA);
		total += func_ov031_022070bc(obj->fieldC);
		total += func_ov031_022054fc(&obj->unknown_14_);
	}
	return total;
}
