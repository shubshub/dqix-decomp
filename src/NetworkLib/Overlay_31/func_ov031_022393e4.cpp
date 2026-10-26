#include <globaldefs.h>

struct Struct_ov031_022393e4 { unsigned char pad[0x40]; int field40; unsigned char pad2[0x10]; int field54; };
struct Struct_ov031_02290d18_7 { unsigned char pad[4]; struct Struct_ov031_022393e4* inner; };
extern struct Struct_ov031_02290d18_7 data_ov031_02290d18;

// USA: func_ov031_022393e4
extern "C" ARM void func_ov031_022393e4(int v) {
	int f = data_ov031_02290d18.inner->field40;
	if ((unsigned int)(f - 9) > 1) {
		data_ov031_02290d18.inner->field54 = v;
	}
}
