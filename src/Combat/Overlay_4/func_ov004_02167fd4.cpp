#include <globaldefs.h>
#include "Resource/GameResources.h"


extern "C" void func_ov017_021baedc(void* a, int b);
extern "C" void* Scenario_GetInstance(void);

struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void func_0206e348(unsigned char* obj, int index, int value);

// USA: func_ov004_02167fd4
extern "C" ARM int func_ov004_02167fd4(void) {
#if defined(jpn)
    enum { Enum_ov004_02167fd4_1844 = 0x524, listOffset = 0x4ec };
#else
    enum { Enum_ov004_02167fd4_1844 = 0x734, listOffset = 0x6fc };
#endif
	char* base = (char*)GetGameResources() + 0x3000;
	struct TailList020469b4* list = *(struct TailList020469b4**)(base + listOffset);
	struct TailNode020469b4* node = *(struct TailNode020469b4**)(base + Enum_ov004_02167fd4_1844);
	func_ov017_021baedc(node, 1);
	*(short*)((char*)node + 0x8) = 0x6fae;
	func_020469b4(list, node);
	unsigned char* p = (unsigned char*)Scenario_GetInstance();
	func_0206e348(p, 0x17, 1);
	return 0;
}
