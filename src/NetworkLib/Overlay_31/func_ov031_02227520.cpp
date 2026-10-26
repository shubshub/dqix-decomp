#include <globaldefs.h>
extern int data_ov031_02250c0c;
// USA: func_ov031_02227520
extern "C" ARM void func_ov031_02227520(int* a, int* b) {
	if (a) *a = *(int*)((char*)&data_ov031_02250c0c + 0x18);
	if (b) *b = *(int*)((char*)&data_ov031_02250c0c + 0x1c);
}
