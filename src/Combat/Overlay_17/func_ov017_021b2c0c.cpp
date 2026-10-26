#include <globaldefs.h>

struct Struct_0206f81c_4 {
	unsigned char pad[0x38];
	union {
		unsigned int unknown1_38_;
		struct {
			unsigned int unknown_0_0_ : 3;
			unsigned int unknown_0_3_ : 1;
			unsigned int unknown_0_4_ : 1;
			unsigned int unknown_0_5_ : 1;
			unsigned int rest : 26;
		} bits;
	};
};

// USA: func_ov017_021b2c0c
extern "C" ARM void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int v) {
	obj->bits.unknown_0_5_ = v;
}
