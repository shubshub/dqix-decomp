#include <globaldefs.h>

struct Struct_ov015_0218bb3c_2 { char pad1[8]; int flags; char pad2[0xa2]; unsigned char unknown_ae_; };

// USA: func_ov015_0218bc9c
extern "C" ARM int func_ov015_0218bc9c(struct Struct_ov015_0218bb3c_2* s) {
	if (s->flags & 0x10) return s->unknown_ae_;
	return -1;
}
