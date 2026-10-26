#include <globaldefs.h>

struct Struct_ov031_02239bc0 { unsigned char pad[8]; int field8; };
struct Struct_ov031_02290d18_16 { unsigned char pad[4]; struct Struct_ov031_02239bc0* inner; };
extern struct Struct_ov031_02290d18_16 data_ov031_02290d18;

// USA: func_ov031_02239bc0
extern "C" ARM void func_ov031_02239bc0(int v) {
	data_ov031_02290d18.inner->field8 = v;
}
