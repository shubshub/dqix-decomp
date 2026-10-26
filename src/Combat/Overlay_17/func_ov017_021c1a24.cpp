#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_020a1e54(int flag);
extern "C" void func_020a1f4c(int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021c1a24 {
	char pad[8];
	SafeAllocator allocator;
	unsigned char unknown_1c_;
	unsigned char unknown_1d_;
	unsigned char pad1e[2];
	int f20;
};

// USA: func_ov017_021c1a24
extern "C" ARM void func_ov017_021c1a24(struct Struct_ov017_021c1a24* self) {
	if (self->f20 != 0) {
		self->f20 = 0;
		#if !defined(jpn)
		if (self->unknown_1d_ != 0) {
			func_020a1e54(1);
		}
		#endif
		func_020a1f4c(1);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}

	self->allocator.ResetAllocatorPointer();
	self->unknown_1c_ = 0;
}
