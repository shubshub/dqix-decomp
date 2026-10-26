#include <globaldefs.h>

struct Struct_ov017_021b1fe8 { unsigned char pad[0x44]; unsigned char unknown_44_; };
struct Struct_ov004_021583a8 { unsigned char pad[0x24]; Struct_ov017_021b1fe8* sub; };

// USA: func_ov017_021b1fe8
extern "C" ARM unsigned char func_ov017_021b1fe8(Struct_ov004_021583a8* obj) {
	Struct_ov017_021b1fe8* sub = obj->sub;
	if (sub) return sub->unknown_44_;
	return 0;
}
