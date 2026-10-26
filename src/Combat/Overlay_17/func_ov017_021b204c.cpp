#include <globaldefs.h>

struct Struct_ov017_021b204c { unsigned char pad[0x438]; unsigned char unknown_438_; };
struct Struct_ov004_0215883c_3 { unsigned char pad[0x24]; Struct_ov017_021b204c* sub; };

// USA: func_ov017_021b204c
extern "C" ARM unsigned char func_ov017_021b204c(Struct_ov004_0215883c_3* obj) {
	Struct_ov017_021b204c* sub = obj->sub;
	if (sub) return sub->unknown_438_;
	return 0;
}
