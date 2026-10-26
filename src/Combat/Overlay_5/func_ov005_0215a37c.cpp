#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
#define STATE_OFFSET 0x3d30
#define RESOURCE_OFFSET 0x34f8
#else
#define STATE_OFFSET 0x3db8
#define RESOURCE_OFFSET 0x3708
#endif

#if defined(jpn)
#define func_ov005_0215a37c func_ov005_0215b8d0
#endif

extern "C" int func_ov017_021a193c(int* obj);
extern "C" int func_ov023_021e3258(void* obj, int a, int b, int c, short d);

// USA: func_ov005_0215a37c
extern "C" ARM void func_ov005_0215a37c(char* obj) {
	if (*(unsigned char*)(obj + STATE_OFFSET) != 3) return;
	char* var0 = (char*)GetGameResources();
	int* p = *(int**)(var0 + RESOURCE_OFFSET);
	int field = func_ov017_021a193c(p);
	func_ov023_021e3258((void*)field, 0xbd, 0x10, 0xbd, 0x2f);
}
