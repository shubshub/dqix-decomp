#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct;
void ClearSearchFlagBit0202c600(struct SearchStruct* obj, int value);
void* LinkMessageQueue_GetInstance(void);
extern "C" void LinkMessageQueue_Reset(void);

struct S02195618 { unsigned char pad[
#if defined(jpn)
0x40c2
#else
0x42e2
#endif
]; unsigned char flag; };

// USA: func_ov017_02195618
ARM void SetFlagAndCleanup_02195618(unsigned char* obj) {
	void* p = LinkSession_GetInstance();
	SetFlags00((GameResources*)obj, 2);
	((S02195618*)obj)->flag = 1;
	ClearSearchFlagBit0202c600((struct SearchStruct*)p, 0);
	LinkMessageQueue_GetInstance();
	LinkMessageQueue_Reset();
}
