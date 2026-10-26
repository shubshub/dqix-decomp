#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_02222eb0(void*);
extern "C" void func_ov031_0223e2b8(void*, void*);
extern "C" void func_ov031_02222fb0(void);

struct Struct_ov031_02222f44 {
	int arr[1];
	unsigned char pad[19];
	unsigned char type;
};
extern Struct_ov031_02222f44* data_ov031_02250ba8;

// USA: func_ov031_02222f44
extern "C" ARM void func_ov031_02222f44(void* a) {
	unsigned int local0, local1;
	Struct_ov031_02222f44* p = data_ov031_02250ba8;
	func_ov031_0223bd28((Struct_ov031_02222f44_2*)p->arr[2], 0, &local0, &local1);
	local1 -= 4;
	func_ov031_02222eb0((void*)local1);
	if ((int)local1 > 0xa8) return;
	func_ov031_02222eb0((void*)0xa8);
	func_ov031_0223e2b8(a, (void*)func_ov031_02222fb0);
}
