#include <globaldefs.h>
#include "Resource/GameResources.h"

// USA: func_ov001_0215fef4
extern "C" ARM int func_ov001_0215fef4(void) {
#if defined(jpn)
    enum { fieldOffset = 0x420 };
#else
    enum { fieldOffset = 0x630 };
#endif
	*(int*)(((char*)GetGameResources() + 0x3000) + fieldOffset) = 0;
	return 1;
}
