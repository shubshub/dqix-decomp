#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(int a);

// USA: func_ov001_021630f4
extern "C" ARM int func_ov001_021630f4(int a) {
#if defined(jpn)
    enum { Enum_ov001_021630f4_1844 = 0x524, fieldOffset = 0xfa };
#else
    enum { Enum_ov001_021630f4_1844 = 0x734, fieldOffset = 0xfe };
#endif
	char* p = *(char**)((char*)GetGameResources() + 0x3000 + Enum_ov001_021630f4_1844);
	*(unsigned char*)(p + fieldOffset) = func_ov017_021d60f4(a) != 0 ? 1 : 0;
	return 1;
}
