#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov023_021f222c_2 {
	unsigned int f0 : 9;
	unsigned int f1 : 9;
	unsigned int f2 : 9;
	unsigned int f3 : 3;
	unsigned int f4 : 2;
};

union Struct_ov023_021f222c {
	struct Struct_ov023_021f222c_2 bits;
	unsigned int raw;
};

struct Struct_ov023_021f1868_11 {
	union Struct_ov023_021f222c word0;
	void *field4;
	int field8;
	char unknown_c_[0x38];
#if defined(jpn)
	char field44[0x118];
#else
	char field44[0x200];
#endif
};

// USA: func_ov023_021f222c
extern "C" ARM void func_ov023_021f222c(struct Struct_ov023_021f1868_11 *obj) {
	obj->word0.bits.f0 = 0;
	obj->word0.bits.f1 = 0;
	obj->word0.bits.f2 = 0;
	obj->word0.bits.f3 = 0;
	obj->word0.bits.f4 = 0;
	obj->field4 = 0;
	obj->field8 = 0;
	memset(obj->unknown_c_, 0, sizeof(obj->unknown_c_));
	memset(obj->field44, 0, sizeof(obj->field44));
	obj->field4 = obj->field44;
}
