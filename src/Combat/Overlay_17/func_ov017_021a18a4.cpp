#include <globaldefs.h>

struct Struct_ov017_021a18a4;
extern "C" void func_ov023_021e3184(Struct_ov017_021a18a4*);

// USA: func_ov017_021a18a4
extern "C" ARM void func_ov017_021a18a4(void* obj) {
	unsigned char flag = *((unsigned char*)obj + 0x22);
	if (flag <= 1) return;
	void* p = *(void**)((char*)obj + 0x1c);
	if (!p) return;
	func_ov023_021e3184((Struct_ov017_021a18a4*)p);
}
