#include <globaldefs.h>

extern "C" unsigned short func_ov031_02239284(void* key);
extern "C" void* func_ov031_02239250(int bit);
extern void* data_ov031_02290d20;

// USA: func_ov031_0223b040
extern "C" ARM int func_ov031_0223b040(void* obj) {
	unsigned short bit = func_ov031_02239284((char*)obj + 0xa);
	if (!bit) return 0;
	void* ptr = func_ov031_02239250(bit);
	*(void**)((char*)data_ov031_02290d20 + (bit - 1) * 4 + 0xaa0) = ptr;
	return 1;
}
