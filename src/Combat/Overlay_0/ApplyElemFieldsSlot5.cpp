#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

int MessageSystem_GetInstance();
extern "C" void func_ov000_02177d04(void* obj, void* buf);

struct StructA0205d5d0;
// USA: func_ov000_02177cb8
ARM int ApplyElemFieldsSlot5_ov000_02177cb8(void* obj) {
	void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
	memset(buf, 0, REGION_OFFSET_1);
	func_ov000_02177d04(obj, buf);
#if defined(jpn)
	return Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0x188), 5, (int)buf, 1);
#else
	return Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0x188), 5, (int)buf, 1, 0);
#endif
}
