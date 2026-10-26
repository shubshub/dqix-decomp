#include <globaldefs.h>

struct Struct_ov031_022410d8 { int length; };

extern "C" int func_ov031_022404e8(Struct_ov031_022410d8* buf, int start, int end, int* arg3);
extern "C" int func_ov031_022405b8(Struct_ov031_022410d8* buf, int start, int end);
extern "C" int func_ov031_02240628(Struct_ov031_022410d8* buf, int start, int end, const char* name, int flags);

// USA: func_ov031_022410d8
extern "C" ARM int func_ov031_022410d8(Struct_ov031_022410d8* buf, const char* name, int* arg2) {
	int var0;
	int var1 = func_ov031_022404e8(buf, 0xc, buf->length, &var0);
	if (var1 <= 0) {
		goto fail;
	}
	{
		int next;
		do {
			next = func_ov031_022404e8(buf, var1, buf->length, &var0);
			if (var0 > 0 && func_ov031_02240628(buf, var1, var0, name, 0) == 0) {
				if (var0 + 1 < buf->length) {
					// volatile read: the ROM reloads the length here instead of reusing the
					// register from the bounds check above.
					int var3 = func_ov031_022404e8(buf, var0 + 1, *(volatile int*)buf, 0);
					int var4;
					if (var3 <= 0) {
						var4 = buf->length;
					} else {
						if (var3 < 2) {
							return -1;
						}
						var4 = var3 - 2;
					}
					int var5 = func_ov031_022405b8(buf, var0 + 1, var4);
					if (var5 < 0) {
						var5 = var4;
					}
					*arg2 = var5;
					return var4 - var5;
				}
				return 0;
			}
			var1 = next;
		} while (next > 0);
	}
fail:
	return -1;
}
