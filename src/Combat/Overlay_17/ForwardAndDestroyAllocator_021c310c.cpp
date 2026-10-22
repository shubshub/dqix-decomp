#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
void ForwardField0xc0_0205ebec(void* obj);
extern "C" void func_02057f00(void* self, int code);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int g_sePlayer;
extern int data_02114e20;

struct Obj021c310c {
	char pad[0x8];
	SafeAllocator allocator;
	char pad2[0x90 - 0x8 - sizeof(SafeAllocator)];
	void* f90;
};

// USA: func_ov017_021c310c  (semantic: ForwardAndDestroyAllocator_021c310c)
extern "C" ARM void func_ov017_021c310c(struct Obj021c310c* self) {
	if (self->f90 != NULL) {
		void* obj = func_02057924(self->f90);
		ForwardField0xc0_0205ebec((void*)&g_sePlayer);
		func_02057f00(obj, 0x11);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
}
