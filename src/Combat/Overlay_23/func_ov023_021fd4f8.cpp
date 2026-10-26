#include <globaldefs.h>

struct Struct_ov023_021fd4f8_2 {
	char pad[0xb8];
	void (*fn)(void*);
};

struct Struct_ov023_021fd4f8 {
	struct Struct_ov023_021fd4f8_2 *unknown_0_;
};

// USA: func_ov023_021fd4f8
extern "C" ARM void func_ov023_021fd4f8(struct Struct_ov023_021fd4f8 *obj) {
	obj->unknown_0_->fn(obj);
}
