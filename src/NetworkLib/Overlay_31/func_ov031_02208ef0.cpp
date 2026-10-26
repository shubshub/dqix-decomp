#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_02208e54(void* dest, const void* data, void* ctx);
extern int data_ov031_02249748;
extern int data_ov031_0224974c;
extern int data_ov031_02249750;

// USA: func_ov031_02208ef0
extern "C" ARM void func_ov031_02208ef0(void* ctx) {
	unsigned char buf[0x30];
	func_ov031_02208e54(buf, &data_ov031_02249748, ctx);
	func_ov031_02208e54(buf + 0x10, &data_ov031_0224974c, ctx);
	func_ov031_02208e54(buf + 0x20, &data_ov031_02249750, ctx);
	VectorizedInvertedMemcpy(buf, ctx, 0x30);
}
