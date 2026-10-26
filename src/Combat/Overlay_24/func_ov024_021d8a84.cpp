#include <globaldefs.h>

extern "C" int func_ov000_02156068(void* obj, int val, int zero, int one);

struct Struct_ov024_021d8a84 { void* field0; };

// USA: func_ov024_021d8a84
extern "C" ARM int func_ov024_021d8a84(struct Struct_ov024_021d8a84* s, int unused, int val, int arg3, int unused4, int count) {
	int result = func_ov000_02156068(s->field0, (short)val, 0, 1);
	if (result) {
		return count + 1;
	}
	return count;
}
