#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kResourceEntryOffset = 0x3524 };
#else
enum { kResourceEntryOffset = 0x3734 };
#endif

extern "C" void* Zone3D_GetInstance(void);
struct Base02019508;
void ClearAndFlagEntry0201ba1c(struct Base02019508* base, int key1, int key2);

struct Obj021cfe84 {
	unsigned char pad0[4];
	unsigned short f4;
	unsigned short f6;
	unsigned short f8;
};

// USA: func_ov017_021cfe84
ARM void ClearAndFlagEntryIfMatch_021cfe84(int unused0, Obj021cfe84* obj) {
	void* basePtr = Zone3D_GetInstance();
	if (obj->f4 != *(unsigned short*)basePtr) {
		return;
	}
	unsigned char* self = (unsigned char*)GetGameResources();
	unsigned char* work = *(unsigned char**)(self + kResourceEntryOffset);
	if (work[3] != 0) {
		return;
	}
	ClearAndFlagEntry0201ba1c((struct Base02019508*)basePtr, obj->f8, obj->f6);
}
