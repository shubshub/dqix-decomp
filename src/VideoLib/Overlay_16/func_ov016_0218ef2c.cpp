#include <globaldefs.h>

struct Struct_ov016_0218e6a8 { char pad0[0x20]; void* unknown_20_; void* pad1; void* unknown_28_; };

// USA: func_ov016_0218ef2c
extern "C" ARM int func_ov016_0218ef2c(struct Struct_ov016_0218e6a8* o) {
	if (o->unknown_20_ == NULL) return 0;
	return o->unknown_28_ != NULL ? 0x80 : 0x100;
}
