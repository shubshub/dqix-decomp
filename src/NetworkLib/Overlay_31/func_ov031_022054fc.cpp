#include <globaldefs.h>

extern "C" int func_ov031_022070bc(int x);

struct Struct_ov031_022054fc {
	unsigned short field0;
	unsigned char field2;
	unsigned char unknown_3_;
};

// USA: func_ov031_022054fc
extern "C" ARM int func_ov031_022054fc(struct Struct_ov031_022054fc* p) {
	int a = func_ov031_022070bc(p->unknown_3_ << 2);
	int b = func_ov031_022070bc(p->field0);
	return a + b;
}
