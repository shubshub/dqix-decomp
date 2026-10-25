#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
void ResetBigStruct02013750(void* obj, int flag);

// USA: func_ov017_0219bf74
ARM void* ResetOverlayAndAllocator_0219bf74(void) {
	unsigned char* self = (unsigned char*)GetGameResources();
	ResetBigStruct02013750(Zone3D_GetInstance(), 1);
	((SafeAllocator*)(self + 0x38))->Reset();
	SetFlags04((GameResources*)self, 2);
	SetFlags00((GameResources*)self, 4);
	return self + 0x38;
}
