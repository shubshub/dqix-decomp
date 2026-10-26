#include <globaldefs.h>

struct Struct_ov017_021b1ffc { unsigned char pad[0x394]; int unknown_394_; };
struct Struct_ov004_021583a8_2 { unsigned char pad[0x24]; Struct_ov017_021b1ffc* sub; };

// USA: func_ov017_021b1ffc
extern "C" ARM int func_ov017_021b1ffc(Struct_ov004_021583a8_2* obj) {
	Struct_ov017_021b1ffc* sub = obj->sub;
	if (sub) return sub->unknown_394_;
	return 0;
}
