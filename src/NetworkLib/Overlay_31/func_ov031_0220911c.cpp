#include <globaldefs.h>

extern "C" void func_ov031_02208c14(void* obj, void* extra, int val);
extern "C" void func_ov031_02208ef0(void* ctx);
extern "C" void func_ov031_02207b44(void* obj, int a, int b);
extern "C" void func_ov031_02208f50(void* obj);

// USA: func_ov031_0220911c
extern "C" ARM void func_ov031_0220911c(void* obj, void* extra) {
	func_ov031_02208c14(obj, extra, *(int*)((char*)obj + 0x81c));
	func_ov031_02208ef0(obj);
	func_ov031_02207b44(obj, 0, 0);
	func_ov031_02208f50(obj);
	*(unsigned char*)((char*)obj + 0x455) = 5;
}
