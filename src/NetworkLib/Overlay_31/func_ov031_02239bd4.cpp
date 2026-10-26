#include <globaldefs.h>

struct Struct_ov031_02239bd4 { unsigned char pad[0x52]; unsigned short unknown_52_; };
struct Struct_ov031_02290d18_17 { unsigned char pad[4]; struct Struct_ov031_02239bd4* inner; };
extern struct Struct_ov031_02290d18_17 data_ov031_02290d18;

// USA: func_ov031_02239bd4
extern "C" ARM unsigned short func_ov031_02239bd4(void) {
	return data_ov031_02290d18.inner->unknown_52_;
}
