#include <globaldefs.h>

extern "C" int func_ov004_0215e47c(int a, int key);
extern "C" void func_ov023_021fc71c(int flag, int val, int c);

extern unsigned char data_ov004_021707e8;

// USA: func_ov004_02162a9c
extern "C" ARM int func_ov004_02162a9c(int a) {
	int flag = func_ov004_0215e47c(a, 0x82);
	if (flag != 0) func_ov023_021fc71c(flag, *(int*)((char*)&data_ov004_021707e8 + 0x1c), 1);
	return 0;
}
