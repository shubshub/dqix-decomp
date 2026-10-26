#include <globaldefs.h>
#include "Resource/Brightness.h"

#if defined(jpn)
enum { kSaveFieldOffset = 0x444 };
#else
enum { kSaveFieldOffset = 0x424 };
#endif

extern "C" ARM void* Zone3D_GetInstance(void);

struct Struct_ov017_021b2ad8 {
	unsigned char pad0[8];
	int f8;
	unsigned char pad1[0x38 - 0xc];
	int unknown_38_;
};

// USA: func_ov017_021b2ad8
extern "C" ARM int func_ov017_021b2ad8(Struct_ov017_021b2ad8* p) {
	if (*(int*)((char*)Zone3D_GetInstance() + kSaveFieldOffset) != 0) {
		return p->f8;
	}
	int h = (int)GetGameResources();
	ClearFlags04((GameResources*)h, 2);
	p->unknown_38_ &= ~1;
	return 3;
}
