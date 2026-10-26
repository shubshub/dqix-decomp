#include <globaldefs.h>

// USA: func_ov001_02158038
extern "C" ARM int func_ov001_02158038(char* a, char* b) {
	if (*(int*)(b + 0x70) != 0) {
		*(int*)(b + 0x88) = *(int*)(a + 0x4);
		*(int*)(b + 0x8c) = *(int*)(a + 0x8);
		*(int*)(b + 0x90) = *(int*)(a + 0xc);
	} else {
		*(int*)(b + 0x64) = *(int*)(a + 0x4);
		*(int*)(b + 0x68) = *(int*)(a + 0x8);
		*(int*)(b + 0x6c) = *(int*)(a + 0xc);
	}
	*(int*)(b + 0xa24) = 1;
	return 0;
}
