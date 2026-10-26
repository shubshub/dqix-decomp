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

extern "C" int MessageSystem_GetInstance();
struct Struct0217f8c0;
struct TableEntry0217f8c0;
extern "C" struct TableEntry0217f8c0* func_ov000_0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02179194(void* obj, void* entry);
extern "C" void func_ov000_0217936c(void* obj, void* entry, void* buf);

struct StructA0205d5d0;
// USA: func_ov000_02179128
extern "C" ARM int func_ov000_02179128(void* obj, int, int) {
	void* entry = func_ov000_0217f8c0((struct Struct0217f8c0*)obj);
	func_ov000_02179194(obj, entry);
	void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
	memset(buf, 0, REGION_OFFSET_1);
	func_ov000_0217936c(obj, entry, buf);
#if defined(jpn)
	return Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0x188), 0x10, (int)buf, 1);
#else
	return Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0x188), 0x10, (int)buf, 1, 0);
#endif
}
