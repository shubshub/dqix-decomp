#include <globaldefs.h>

struct Struct_ov031_0223caec { char pad[0x67c]; unsigned char unknown_67c_; unsigned char unknown_67d_; };
extern struct Struct_ov031_0223caec* data_ov031_02290d38;

// USA: func_ov031_0223caec
extern "C" ARM void func_ov031_0223caec(void* ptr) {
	struct Struct_ov031_0223caec* base = data_ov031_02290d38;
	if (ptr == (char*)base + 0x610) {
		base->unknown_67c_ = 1;
	} else {
		base->unknown_67d_ = 1;
	}
}
