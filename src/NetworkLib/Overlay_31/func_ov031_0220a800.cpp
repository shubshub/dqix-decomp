#include <globaldefs.h>

extern "C" void func_ov031_0220a6bc(void* self);

// USA: func_ov031_0220a800
extern "C" ARM int func_ov031_0220a800(char* self) {
	char* ctx = *(char**)(self + 0xc);
	if (!(*(int*)(ctx + 0x824) != 0 && *(unsigned char*)(ctx + 0x456) != 0)) {
		func_ov031_0220a6bc(self);
	}
	int handle = *(int*)(ctx + 0x824);
	if (handle != 0 && *(unsigned char*)(ctx + 0x456) != 0) {
		return *(int*)(ctx + 0x828) - *(int*)(ctx + 0x82c);
	}
	if (handle != 0) {
		goto ret_zero;
	}
	if (*(unsigned char*)(self + 8) != 4) {
		goto ret_neg1;
	}
	if (*(unsigned char*)(ctx + 0x455) != 9) {
		goto ret_zero;
	}
ret_neg1:
	return -1;
ret_zero:
	return 0;
}
