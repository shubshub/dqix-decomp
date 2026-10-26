#include <globaldefs.h>

struct Struct_ov017_021b2060 { unsigned char pad[0x439]; unsigned char unknown_439_; };
struct Struct_ov004_0215883c_4 { unsigned char pad[0x24]; Struct_ov017_021b2060* sub; };

// USA: func_ov017_021b2060
extern "C" ARM unsigned char func_ov017_021b2060(Struct_ov004_0215883c_4* obj) {
	Struct_ov017_021b2060* sub = obj->sub;
	if (sub) return sub->unknown_439_;
	return 0;
}
