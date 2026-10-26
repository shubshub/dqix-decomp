#include <globaldefs.h>

extern "C" int func_ov031_022056bc(void*, unsigned short);

struct Struct_ov031_02207204 {
	unsigned short pad0;
	unsigned short field2;
};

// USA: func_ov031_02207204
extern "C" ARM int func_ov031_02207204(void* obj, struct Struct_ov031_02207204* arg1) {
	unsigned int v = arg1->field2;
	unsigned int hi = ((int)v >> 8) & 0xff;
	unsigned int lo = (v << 8) & 0xff00;
	unsigned short swapped = (unsigned short)(hi | lo);
	return func_ov031_022056bc(obj, swapped);
}
