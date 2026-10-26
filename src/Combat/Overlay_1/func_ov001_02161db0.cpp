#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* a);

// USA: func_ov001_02161db0
extern "C" ARM int func_ov001_02161db0(void *a) {
#if defined(jpn)
    enum { Enum_ov001_02161db0_1844 = 0x524, Enum_ov001_02161db0_208 = 0xcc };
#else
    enum { Enum_ov001_02161db0_1844 = 0x734, Enum_ov001_02161db0_208 = 0xd0 };
#endif
	char* p = *(char**)((char*)GetGameResources() + 0x3000 + Enum_ov001_02161db0_1844);
	int id = func_ov017_021d60f4(a);
	char* node = *(char**)(p + Enum_ov001_02161db0_208);
	while (node != 0) {
		if (*(unsigned char*)(node + 1) == id) {
			*(unsigned char*)(node + 4) |= 1;
			break;
		}
		node = *(char**)(node + 0x34);
	}
	return 1;
}
