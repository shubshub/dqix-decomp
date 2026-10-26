#include <globaldefs.h>

struct Struct_ov017_021b2024 { unsigned char pad[0x34]; unsigned char unknown_34_; };
struct Struct_ov004_021583a8_4 { unsigned char pad[0x24]; Struct_ov017_021b2024* sub; };

// USA: func_ov017_021b2024
extern "C" ARM unsigned char func_ov017_021b2024(Struct_ov004_021583a8_4* obj) {
	Struct_ov017_021b2024* sub = obj->sub;
	if (sub) return sub->unknown_34_;
	return 0;
}
