#include <globaldefs.h>

extern "C" void func_ov031_0220ab94(void* dst, const void* src, unsigned int length);
extern "C" void func_ov031_0220b028(void* ctx, const void* data, unsigned int len);
extern unsigned char data_ov031_022497a4[];

// USA: func_ov031_0220b0e0
extern "C" ARM void func_ov031_0220b0e0(void* ctx, void* out) {
	func_ov031_0220ab94(out, (char*)ctx + 0x10, 8);
	int var0 = (*(unsigned int*)((char*)ctx + 0x10) >> 3) & 0x3f;
	int var1 = (var0 < 0x38) ? (0x38 - var0) : (0x78 - var0);
	func_ov031_0220b028(ctx, data_ov031_022497a4, var1);
	func_ov031_0220b028(ctx, out, 8);
	func_ov031_0220ab94(out, ctx, 0x10);
}
