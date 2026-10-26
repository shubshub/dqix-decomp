#include <globaldefs.h>

extern "C" void func_ov031_0220bab8(void* ctx, void* data, int len);

// USA: func_ov031_022093f4
extern "C" ARM int func_ov031_022093f4(void* obj, void* data, int len) {
	func_ov031_0220bab8((char*)obj + 0x1e0, data, len);
	return len;
}
