#include <globaldefs.h>
#include "Resource/Brightness.h"

struct HeadNode02046b24;

extern "C" void func_ov017_021d6134(void* obj, int val);
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

// USA: func_ov001_02162f8c
extern "C" ARM int func_ov001_02162f8c(void* obj) {
#if defined(jpn)
    enum { Enum_ov001_02162f8c_1792 = 0x4f0 };
#else
    enum { Enum_ov001_02162f8c_1792 = 0x700 };
#endif
	unsigned int* p = (unsigned int*)GetGameResources();
	if (TestFlags00((GameResources*)p, 0x10) != 0) {
		func_ov017_021d6134(obj, 0);
		return 1;
	}
	struct HeadNode02046b24** list = *(struct HeadNode02046b24***)((char*)p + 0x3000 + Enum_ov001_02162f8c_1792);
	int id = FieldTaskQueue_GetCurrentKind(list);
	int var3 = (id != 0x13);
	func_ov017_021d6134(obj, var3 == 0);
	if (var3) {
		SetFlags00((GameResources*)p, 0x10);
	}
	return 1;
}
