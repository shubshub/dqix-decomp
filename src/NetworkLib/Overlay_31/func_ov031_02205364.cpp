#include <globaldefs.h>

extern "C" void* func_ov031_02205414(void* arg);

struct Struct_ov031_02205194;
extern "C" void* func_ov031_02205134(void* a, void* b, int c);
extern "C" int func_ov031_0220529c(Struct_ov031_02205194* obj, void* extra);

extern "C" void func_ov031_022053a0(void);

// USA: func_ov031_02205364
extern "C" ARM int func_ov031_02205364(void* arg) {
	void* obj = func_ov031_02205414(arg);
	if (!obj) return -0x31;
	void* extra = func_ov031_02205134((void*)func_ov031_022053a0, obj, 1);
	func_ov031_0220529c((Struct_ov031_02205194*)obj, extra);
	return (int)obj;
}
