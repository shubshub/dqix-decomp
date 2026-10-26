#include <globaldefs.h>

extern "C" int func_ov024_021fe698(char* obj, int idx);
extern "C" int func_ov024_021fdf04(void* obj, int idx);
extern "C" int func_ov024_021fd954(void* obj, int idx);

struct Struct_ov024_021fbe3c { unsigned int unknown_0_0_ : 8; unsigned int unknown_1_0_ : 2; };

// USA: func_ov024_021fbe3c
extern "C" ARM int func_ov024_021fbe3c(void* obj) {
	void* p = *(void**)((char*)obj + 0x64c);
	struct Struct_ov024_021fbe3c* var1 = (struct Struct_ov024_021fbe3c*)((char*)p + 8);
	int r;
	if (var1->unknown_1_0_ == 1) {
		r = func_ov024_021fe698((char*)obj, 3);
		if (!r) {
			return r;
		}
		r = func_ov024_021fe698((char*)obj, 0xf);
		if (!r) {
			return r;
		}
		return func_ov024_021fdf04(obj, 0x13);
	} else {
		r = func_ov024_021fe698((char*)obj, 3);
		if (!r) {
			return r;
		}
		r = func_ov024_021fe698((char*)obj, 7);
		if (!r) {
			return r;
		}
		return func_ov024_021fd954(obj, 0x13);
	}
}
