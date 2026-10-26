#include <globaldefs.h>
extern int data_ov031_02250c0c;

// USA: func_ov031_0222750c
extern "C" ARM void func_ov031_0222750c(int a, int b) {
	*(int*)((char*)&data_ov031_02250c0c + 0x18) = a;
	*(int*)((char*)&data_ov031_02250c0c + 0x1c) = b;
}
