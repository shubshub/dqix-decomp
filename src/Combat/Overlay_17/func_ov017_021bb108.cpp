#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void DestroyActiveAllocators_0215aa5c(void);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

// USA: func_ov017_021bb108
extern "C" ARM void func_ov017_021bb108(char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_021bb108_124=0x78, Enum_ov017_021bb108_292=0x120, Enum_ov017_021bb108_312=0x134};
#else
 enum {Enum_ov017_021bb108_124=0x7c, Enum_ov017_021bb108_292=0x124, Enum_ov017_021bb108_312=0x138};
#endif
	void* var0 = ((SafeAllocator*)(arg0 + Enum_ov017_021bb108_124))->GetSignedAllocator();
	if (var0 != NULL) {
		func_ov001_0215aa5c();
		void* var1 = ((SafeAllocator*)(arg0 + Enum_ov017_021bb108_292))->GetSignedAllocator();
		if (var1 != NULL) {
			((SafeAllocator*)(arg0 + Enum_ov017_021bb108_292))->Destroy();
			((SafeAllocator*)(arg0 + Enum_ov017_021bb108_124))->Free(var1);
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
