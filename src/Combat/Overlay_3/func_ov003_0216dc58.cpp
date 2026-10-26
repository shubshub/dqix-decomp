#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { kRegion1324 = 0x11b4 };
#else
enum { kRegion12c0 = 0x12c0 };
enum { kRegion1324 = 0x1324 };
#endif

extern "C" void __clear(void* buf, int len);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" int Text_Append(char* dst, const char* src);

struct StructA0205d5d0;
// USA: func_ov003_0216dc58  (semantic: BuildAndApplyScaleMessage_0216dc58)
extern "C" ARM void func_ov003_0216dc58(char* obj) {
	char buf1[0x100];
	char buf2[0x40];
	int field;
	__clear(buf1, 0x100);
	__clear(buf2, 0x40);
	if (*(int*)(obj + 0x10) == 2) {
		int sum = Window_GetSelectedIndex(*(struct Struct_0205c570**)(obj + kRegion12c0));
		Text_AppendFrameTag(buf1, sum, 8, 5, 5, 5);
	}
	field = KeyTable_Get((struct Container020e0310*)(obj + kRegion1324), 0x5c);
	Text_Append(buf1, (const char*)field);
#if defined(jpn)
	Window_SetPaneText((struct StructA0205d5d0*)(*(void**)(obj + kRegion12c0)), 0, (int)buf1, 1);
#else
	Window_SetPaneText((struct StructA0205d5d0*)(*(void**)(obj + kRegion12c0)), 0, (int)buf1, 1, 0);
#endif
}
