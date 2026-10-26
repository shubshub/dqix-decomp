#include <globaldefs.h>
#include "std_library_functions.h"

struct SearchStruct;
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_0202c600(struct SearchStruct* obj, int value);
extern "C" void func_ov017_02195214(void* dst, void* src);

// USA: func_ov017_0219541c
extern "C" ARM void func_ov017_0219541c(void* obj, int idx, char* arg2) {
#if defined(jpn)
 enum {regionalOffset0=0xd1, regionalOffset1=0x4000, regionalOffset2=0x16c};
#else
 enum {regionalOffset0=0xf1, regionalOffset1=0x4200, regionalOffset2=0x41c};
#endif
	void* searchObj = LinkSession_GetInstance();
	int idx1 = idx - 1;
	unsigned char* ptr;
	if (idx1 < 0) return;
	if (idx1 > 2) return;
	func_ov017_02195214((unsigned char*)obj + regionalOffset0 + regionalOffset1 + idx1 * 15, arg2);
	func_0202c600((struct SearchStruct*)searchObj, idx);
	ptr = *(unsigned char**)((char*)obj + 0x4000 + regionalOffset2);
	if (ptr[0] != 1) return;
	if (ptr[2] != idx) return;
	strcpy((char*)ptr + 4, arg2 + 2);
}
