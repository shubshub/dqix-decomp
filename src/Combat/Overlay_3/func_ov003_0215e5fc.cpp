#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Array0215e85c;
extern "C" void func_ov003_0215e85c(struct Array0215e85c* self, class SafeAllocator* allocator, int count);

extern int KeyboardLayout_scriptContext;

// USA: func_ov003_0215e5fc
extern "C" ARM int func_ov003_0215e5fc(struct Variant02030b0c* v) {
	int count = ((Script::Parameter*)v)->ToInt();
	SafeAllocator* alloc = (SafeAllocator*)*(int*)&KeyboardLayout_scriptContext;
	struct Array0215e85c* obj = (struct Array0215e85c*)*(int*)((char*)&KeyboardLayout_scriptContext + 4);
	func_ov003_0215e85c(obj, alloc, (short)count);
	return 1;
}
