#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215be20_2400 = 0x800 };
#else
enum { Enum_ov003_0215be20_2400 = 0x960 };
#endif
#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" void func_ov003_0215b964(void* obj, void* p, int flag);

// USA: func_ov003_0215be20
extern "C" ARM void func_ov003_0215be20(void* obj) {
	memset(*(void**)((char*)obj + 0x7c), 0, Enum_ov003_0215be20_2400);
	func_ov003_0215b964(obj, *(void**)((char*)obj + 0x7c), 0);
#if defined(jpn)
	Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0xf4), 2, *(int*)((char*)obj + 0x7c), 1);
#else
	Window_SetPaneText((StructA0205d5d0*)((char*)obj + 0xf4), 2, *(int*)((char*)obj + 0x7c), 1, 0);
#endif
}
