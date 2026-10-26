#include <globaldefs.h>

struct Struct_ov031_0223b30c { unsigned char pad[0x144]; unsigned short unknown_144_; };
extern struct Struct_ov031_0223b30c* data_ov031_02290d20;

// USA: func_ov031_0223b30c
extern "C" ARM unsigned short func_ov031_0223b30c(void) {
	return data_ov031_02290d20->unknown_144_;
}
