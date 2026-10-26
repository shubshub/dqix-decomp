#include <globaldefs.h>

extern void* data_ov031_0224e580;
extern "C" void func_ov031_02211864(int a, int b);

// USA: func_ov031_0220fff8
extern "C" ARM int func_ov031_0220fff8(int* obj) {
	if (*(int*)((char*)obj + 8) == 0xd6 && *(int*)((char*)obj + 0xc) != 0) {
		int field10 = *(int*)((char*)obj + 0x10);
		if (field10 == 0) {
			func_ov031_02211864(6, 6 - 0x1a);
		}
		*(int*)((char*)data_ov031_0224e580 + 0x30) = field10;
	}
	return 1;
}
