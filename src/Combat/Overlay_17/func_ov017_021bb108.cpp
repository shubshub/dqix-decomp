#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_ov001_0215aa5c(void);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

// USA: func_ov017_021bb108
extern "C" ARM void func_ov017_021bb108(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x78, regionalOffset1=0x120, regionalOffset2=0x134};
#else
 enum {regionalOffset0=0x7c, regionalOffset1=0x124, regionalOffset2=0x138};
#endif
	void* p1 = ((SafeAllocator*)(self + regionalOffset0))->GetSignedAllocator();
	if (p1 != NULL) {
		func_ov001_0215aa5c();
		void* p2 = ((SafeAllocator*)(self + regionalOffset1))->GetSignedAllocator();
		if (p2 != NULL) {
			((SafeAllocator*)(self + regionalOffset1))->Destroy();
			((SafeAllocator*)(self + regionalOffset0))->Free(p2);
		}
		void* p3 = ((SafeAllocator*)(self + regionalOffset0))->GetSignedAllocator();
		((SafeAllocator*)(self + regionalOffset0))->Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p3);
	}
	if (*(SafeAllocator**)(self + regionalOffset2) == NULL) return;
	void* p4 = (*(SafeAllocator**)(self + regionalOffset2))->GetSignedAllocator();
	if (p4 == NULL) return;
	(*(SafeAllocator**)(self + regionalOffset2))->Destroy();
	AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p4);
	*(SafeAllocator**)(self + regionalOffset2) = NULL;
}
