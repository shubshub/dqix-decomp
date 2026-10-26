#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(int a);
extern "C" void func_ov017_021bbbec(void* p, unsigned short v);

// USA: func_ov001_0215f9dc
extern "C" ARM int func_ov001_0215f9dc(int id) {
#if defined(jpn)
    enum { fieldOffset = 0x524 };
#else
    enum { fieldOffset = 0x734 };
#endif
	void* p = *(void**)((char*)GetGameResources() + 0x3000 + fieldOffset);
	func_ov017_021bbbec(p, (unsigned short)func_ov017_021d60f4(id));
	return 1;
}
