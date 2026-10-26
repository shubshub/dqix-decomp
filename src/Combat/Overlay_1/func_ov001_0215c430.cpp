#include <globaldefs.h>

extern "C" void* func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(void* p);
extern "C" void* func_ov001_0215a3d8(void* ctx, int val);

// USA: func_ov001_0215c430
extern "C" ARM int func_ov001_0215c430(void* obj) {
	void* ctx = func_ov001_0215ab20(func_ov017_021d60f4(obj));
	if (!ctx) return 0;
	int val = (int)func_ov017_021d60f4((char*)obj + 8);
	func_ov001_0215a3d8(ctx, val);
	return 1;
}
