#include <globaldefs.h>

extern void* data_ov031_0224e580;

// USA: func_ov031_0220fdec
extern "C" ARM void func_ov031_0220fdec(int a, int* b) {
	int result = 1;
	if (!(a < 0) && !((unsigned int)a < 12) && *b == a) {
		int (*fn)(int*) = *(int(**)(int*))((char*)data_ov031_0224e580 + 0x28);
		if (fn != NULL) {
			result = fn(b);
		}
	}
	*(int*)((char*)data_ov031_0224e580 + 0x2c) = result;
}
