#include <globaldefs.h>

struct Struct_ov016_0219d144_6 {
	int unknown_0_;      // 0x0
	#if defined(jpn)
 char pad0[0x10 - 0x4];
#else
 char pad0[0x14 - 0x4];
#endif
	int unknown_14_;     // 0x14
	int unknown_18_;  // 0x18
};

extern Struct_ov016_0219d144_6 data_ov016_0219d144;

// USA: func_ov016_0218d294
extern "C" ARM void func_ov016_0218d294(void) {
	data_ov016_0219d144.unknown_0_ = 1;
	if (data_ov016_0219d144.unknown_14_ == 0) data_ov016_0219d144.unknown_18_++;
}
