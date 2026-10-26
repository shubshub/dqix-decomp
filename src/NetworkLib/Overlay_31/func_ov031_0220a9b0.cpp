#include <globaldefs.h>

extern "C" void* func_ov031_0220963c(void* ctx, void* buf);
extern "C" void func_ov031_022037a8(void* buf, void* p1, int p2, int p3, void* self);

// USA: func_ov031_0220a9b0
extern "C" ARM void func_ov031_0220a9b0(void* self) {
	char* ctx = *(char**)((char*)self + 0xc);
	if (*(unsigned char*)(ctx + 0x455) == 8) {
		unsigned char buf[0x1c];
		buf[0] = 0x15;
		buf[1] = 0x3;
		buf[2] = 0;
		buf[3] = 0;
		buf[4] = 0x2;
		buf[5] = 0x1;
		buf[6] = 0;
		func_ov031_022037a8(buf, func_ov031_0220963c(ctx, buf), 0, 0, self);
	}
	*(unsigned char*)(ctx + 0x455) = 0;
}
