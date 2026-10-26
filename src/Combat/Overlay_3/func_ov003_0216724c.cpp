#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov003_0216724c {
	void* field0;
	SafeAllocator* unknown_4_;
};

struct Struct_ov003_0217f4e4 { unsigned int v[3]; };
extern struct Struct_ov003_0217f4e4 data_ov003_0217f4e4;

// USA: func_ov003_0216724c
extern "C" ARM void func_ov003_0216724c(struct Struct_ov003_0216724c* obj, SafeAllocator* alloc) {
	int i;
	struct Struct_ov003_0217f4e4 sizes;
	if (alloc == NULL) return;
	obj->unknown_4_ = (SafeAllocator*)alloc->Allocate(0x3c);
	sizes = data_ov003_0217f4e4;
	for (i = 0; i < 3; i++) {
		unsigned int sz = sizes.v[i];
		void* p = alloc->Allocate(sz);
		obj->unknown_4_[i].CreateTypeA(p, sz);
	}
	if (obj->field0 == NULL) {
		obj->field0 = alloc->Allocate(0x4000);
	}
}
