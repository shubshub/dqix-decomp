#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_0220b8f4(void* ctx, const void* data, unsigned int len);
extern "C" void func_ov031_0220b8a0(unsigned int* ctx);
extern "C" void func_ov031_0220b9ac(void* ctx, void* out);
extern unsigned char data_ov031_02249754[];
extern unsigned char data_ov031_0224975c[];

// USA: func_ov031_02209234
extern "C" ARM void func_ov031_02209234(void* obj, void* out, int mode) {
	unsigned char pad[0x28];
	void* ctx = (char*)obj + 0x2ec;
	if ((*(unsigned char*)((char*)obj + 0x454) ^ mode) != 0) {
		func_ov031_0220b8f4(ctx, data_ov031_02249754, 4);
	} else {
		func_ov031_0220b8f4(ctx, data_ov031_0224975c, 4);
	}
	func_ov031_0220b8f4(ctx, obj, 0x30);
	VectorizedMemset(pad, 0x36, 0x28);
	func_ov031_0220b8f4(ctx, pad, 0x28);
	func_ov031_0220b9ac(ctx, out);
	func_ov031_0220b8a0((unsigned int*)ctx);
	func_ov031_0220b8f4(ctx, obj, 0x30);
	VectorizedMemset(pad, 0x5c, 0x28);
	func_ov031_0220b8f4(ctx, pad, 0x28);
	func_ov031_0220b8f4(ctx, out, 0x14);
	func_ov031_0220b9ac(ctx, out);
}
