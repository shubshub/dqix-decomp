#include <globaldefs.h>

extern "C" void* func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(void* p);
extern "C" void* func_ov001_0215a530(void* ctx, int a);

// USA: func_ov001_0215c544
extern "C" ARM int func_ov001_0215c544(void* obj) {
	void* ctx = func_ov001_0215ab20(func_ov017_021d60f4(obj));
	if (!ctx) return 0;
	int val = (int)func_ov017_021d60f4((char*)obj + 8);
	func_ov001_0215a530(ctx, val);
	return 1;
}
