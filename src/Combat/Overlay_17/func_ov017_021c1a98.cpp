#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION_FIELD_0 0x958
#define REGION_FIELD_1 0x4ec
#else
#define REGION_FIELD_0 0xb78
#define REGION_FIELD_1 0x6fc
#endif


extern "C" void func_ov017_021c1acc(unsigned char* self);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021c1a98
extern "C" ARM void func_ov017_021c1a98(void* unused, int val) {
	char* base = (char*)GetGameResources() + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + REGION_FIELD_1);
	unsigned char* node = *(unsigned char**)(base + REGION_FIELD_0);
	func_ov017_021c1acc(node);
	*(int*)(node + 0xc) = val;
	func_020469b4(list, (TailNode020469b4*)node);
}
