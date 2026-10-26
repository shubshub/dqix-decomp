#include <globaldefs.h>

extern "C" void func_ov004_0216afb0(void* obj, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern "C" void func_ov004_0216b390(void* obj, int a1, int a2);
extern unsigned char data_ov004_02171034;

// USA: func_ov004_0216b498
extern "C" ARM void func_ov004_0216b498(void* a, int idx, int mode) {
	int flag = 1;
	switch (idx) {
	case 0:
		func_ov004_0216afb0(a, 0x32, 1, 0xd2, 0x23, 0xc, 6, 0xa, flag);
		func_ov004_0216afb0(a, 0x33, 1, 0xd2, 0x35, 0xc, 0x13, 0xa, 1);
		func_ov004_0216afb0(a, 0x34, 1, 0xd2, 0x3c, 0xc, 0x20, 0xa, 1);
		break;
	case 1:
		if (mode == 0) {
			if (((unsigned char*)&data_ov004_02171034)[3] == 5) flag = 0;
			func_ov004_0216afb0(a, 0x32, 1, 0xd2, 2, 0xc, 6, 0xa, flag);
			func_ov004_0216afb0(a, 0x33, 1, 0xd2, 3, 0xc, 0x13, 0xa, 1);
			func_ov004_0216afb0(a, 0x34, 1, 0xd2, 0x3c, 0xc, 0x20, 0xa, 1);
			func_ov004_0216b390(a, 0x34, mode);
		} else {
			if (((unsigned char*)&data_ov004_02171034)[3] == 5) flag = 0;
			func_ov004_0216afb0(a, 0x32, 1, 0xd2, 2, 0xc, 6, 0xa, flag);
			func_ov004_0216afb0(a, 0x33, 1, 0xd2, 3, 0xc, 0x13, 0xa, 1);
			func_ov004_0216afb0(a, 0x34, 1, 0xd2, 0x3c, 0xc, 0x20, 0xa, 1);
			func_ov004_0216b390(a, 0x34, mode);
		}
		break;
	case 2:
		func_ov004_0216afb0(a, 0x32, 1, 0xd2, flag, 0xc, 8, 0xa, flag);
		func_ov004_0216afb0(a, 0x33, 1, 0xd2, 0x3c, 0xc, 0x16, 0xa, 1);
		func_ov004_0216b390(a, 0x33, 3);
		break;
	case 3:
		func_ov004_0216afb0(a, 0x32, 1, 0xd2, 2, 0xc, 7, 0xa, flag);
		break;
	}
}
