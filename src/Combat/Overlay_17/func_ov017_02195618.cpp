#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct;
extern "C" void func_0202c600(struct SearchStruct* obj, int value);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void LinkMessageQueue_Reset(void);

struct Struct_ov017_02195618 { unsigned char pad[
#if defined(jpn)
0x40c2
#else
0x42e2
#endif
]; unsigned char flag; };

// USA: func_ov017_02195618
extern "C" ARM void func_ov017_02195618(unsigned char* obj) {
	void* p = LinkSession_GetInstance();
	SetFlags00((GameResources*)obj, 2);
	((Struct_ov017_02195618*)obj)->flag = 1;
	func_0202c600((struct SearchStruct*)p, 0);
	LinkMessageQueue_GetInstance();
	LinkMessageQueue_Reset();
}
