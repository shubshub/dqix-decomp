#include <globaldefs.h>

struct Struct_ov017_021b2010 { unsigned char pad[0x398]; unsigned char unknown_398_; };
struct Struct_ov004_021583a8_3 { unsigned char pad[0x24]; Struct_ov017_021b2010* sub; };

// USA: func_ov017_021b2010
extern "C" ARM unsigned char func_ov017_021b2010(Struct_ov004_021583a8_3* obj) {
	Struct_ov017_021b2010* sub = obj->sub;
	if (sub) return sub->unknown_398_;
	return 0;
}
