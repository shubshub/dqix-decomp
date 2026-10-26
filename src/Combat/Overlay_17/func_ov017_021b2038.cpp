#include <globaldefs.h>

struct Struct_ov017_021b2038 { unsigned char pad[0x35]; unsigned char unknown_35_; };
struct Struct_ov004_021583a8_5 { unsigned char pad[0x24]; Struct_ov017_021b2038* sub; };

// USA: func_ov017_021b2038
extern "C" ARM unsigned char func_ov017_021b2038(Struct_ov004_021583a8_5* obj) {
	Struct_ov017_021b2038* sub = obj->sub;
	if (sub) return sub->unknown_35_;
	return 0;
}
