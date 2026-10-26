#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov017_021c12b0(unsigned char param);
extern int data_ov017_021d8478;
extern "C" void func_020a1f4c(int flag);
extern "C" void func_020a1e54(int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

struct Struct_ov017_021c1394 {
	char pad[8];
	SafeAllocator allocator;
};

// USA: func_ov017_021c1394
extern "C" ARM void func_ov017_021c1394(Struct_ov017_021c1394* self) {
	if (*(unsigned char*)((char*)self + 0x1e) != 0) {
		func_ov017_021c12b0(0);
	}
	if (data_ov017_021d8478 != 0) {
		data_ov017_021d8478 = 0;
		func_020a1f4c(1);
		func_020a1e54(1);
	}
	void* p = self->allocator.GetSignedAllocator();
	self->allocator.Destroy();
	AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
}
