#include <globaldefs.h>

struct Struct_ov031_02239be8 { unsigned char pad[0x40]; int field40; };
struct Struct_ov031_02290d18_18 { unsigned char pad[4]; struct Struct_ov031_02239be8* inner; };
extern struct Struct_ov031_02290d18_18 data_ov031_02290d18;

// USA: func_ov031_02239be8
extern "C" ARM int func_ov031_02239be8(void) {
	return data_ov031_02290d18.inner->field40;
}
