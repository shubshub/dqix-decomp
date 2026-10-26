#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void func_ov004_02153e20(void*);

// USA: func_ov004_02154038
extern "C" ARM int func_ov004_02154038(void* a) {
	void* base = func_ov011_021849c8(a);
	void* obj = func_ov023_021f6880(base, 0x2c);
	if (!obj) return 0;
	if (func_ov023_021f6f10(obj) != 7) return 0;
	void* obj2 = func_ov023_021f6880(base, 3);
	if (!obj2) return 0;
	if (func_ov023_021f6f10(obj2) != 6) return 0;
	func_ov004_02153e20(a);
	return 0;
}
