#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
#define REGION_FIELD_0 0x4ec
#define REGION_FIELD_1 0x95c
#else
#define REGION_FIELD_0 0x6fc
#define REGION_FIELD_1 0xb7c
#endif


extern "C" ARM void func_ov017_021a8670(char* obj);
extern "C" ARM void func_ov017_021a932c(void* obj, int val);
struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021a8614
extern "C" ARM void func_ov017_021a8614(void* unused, int val, unsigned char b0, unsigned char b1, int b2, int b3) {
	char* base = (char*)(int)GetGameResources() + 0x3000;
	struct TailList020469b4* list = *(struct TailList020469b4**)(base + REGION_FIELD_0);
	char* node = *(char**)(base + REGION_FIELD_1);
	func_ov017_021a8670(node);
	func_ov017_021a932c(node, val);
	node[0x18] = b0;
	node[0x19] = b1;
	node[0x1a] = b2;
	node[0x1b] = b3;
	func_020469b4(list, (struct TailNode020469b4*)node);
}
