#include <globaldefs.h>

struct Struct_ov031_02213230 { int (*fn)(int, void*); unsigned char pad[4]; unsigned char field8; };
extern "C" Struct_ov031_02213230* func_ov031_022133f8(int);

// USA: func_ov031_02213230
extern "C" ARM int func_ov031_02213230(int mask, void* arg) {
	Struct_ov031_02213230* t = func_ov031_022133f8(1);
	if (t->field8 & mask) return 0;
	t->field8 |= mask;
	return t->fn(mask, arg);
}
