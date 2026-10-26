#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Container0215e750;
extern "C" void func_ov003_0215e750(struct Container0215e750* obj, SafeAllocator* alloc, int count);

extern int KeyboardLayout_scriptContext;

// USA: func_ov003_0215e4e4
extern "C" ARM int func_ov003_0215e4e4(struct Variant02030b0c* v) {
	int count = ((Script::Parameter*)v)->ToInt();
	SafeAllocator* alloc = (SafeAllocator*)*(int*)&KeyboardLayout_scriptContext;
	struct Container0215e750* obj = (struct Container0215e750*)*(int*)((char*)&KeyboardLayout_scriptContext + 4);
	func_ov003_0215e750(obj, alloc, (short)count);
	return 1;
}
