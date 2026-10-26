#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void*, int);
extern "C" int func_ov000_0215e9fc(int a0, void* buf, int max, int flag);

struct Struct_ov024_021f18a0 { int field0; };

// USA: func_ov024_021f18a0
extern "C" ARM int func_ov024_021f18a0(struct Struct_ov024_021f18a0* obj, int b, int c, int* out, void* e) {
	short buf[4];
	__clear(buf, 8);
	int count = func_ov000_0215e9fc(obj->field0, buf, 4, 1);
	if (count <= 0) return 0;
	*out = count;
	memcpy(e, buf, 8);
	return 1;
}
