#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* obj, int key);

// USA: func_ov004_021634b8
extern "C" ARM void func_ov004_021634b8(void* a, int key, int value) {
	void* base = func_ov011_021849c8(a);
	void* node = func_ov023_021f6880(base, key);
	if (node != NULL) {
		*((unsigned char*)node + 0x3a) = (unsigned char)value;
	}
}
