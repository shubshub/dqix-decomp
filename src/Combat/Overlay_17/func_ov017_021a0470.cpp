#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_020545b8;
extern "C" void func_020545b8(struct Struct_020545b8* obj);
extern "C" int AllocatorUnion_Free(AllocatorUnion*, void*);

extern AllocatorUnion g_mainAllocator;
extern int data_ov017_021d68cc[];

// USA: func_ov017_021a0470
extern "C" ARM void func_ov017_021a0470(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0xb8};
#else
 enum {regionalOffset0=0x2c8};
#endif
	char* group = self + regionalOffset0;
	int i = 0;
	group = group + 0x1000;
	for (; i < 4; i++) {
		func_020545b8((struct Struct_020545b8*)(group + i * 0x5ec));
	}

	for (int i = 0; data_ov017_021d68cc[i] >= 0; i++) {
		int off = data_ov017_021d68cc[i] * 0x14;
		void* p = ((SafeAllocator*)(self + 0x38 + off))->GetSignedAllocator();
		((SafeAllocator*)(self + 0x38 + off))->Destroy();
		((SafeAllocator*)(self + 0x38 + off))->ResetAllocatorPointer();
		if (p != NULL) {
			AllocatorUnion_Free(&g_mainAllocator, p);
		}
	}
}
