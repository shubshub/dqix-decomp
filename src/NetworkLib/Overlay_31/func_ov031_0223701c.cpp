#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_022370f8(void*);

struct Struct_ov031_02290d04_12 { char pad[4]; int* p; };
extern Struct_ov031_02290d04_12 data_ov031_02290d04;

struct Struct_ov031_0224926a_6 { unsigned short lo; unsigned short hi; };
extern Struct_ov031_0224926a_6 data_ov031_0224926a[];

// USA: func_ov031_0223701c
extern "C" ARM void func_ov031_0223701c(void* obj) {
	unsigned int var0, var1;
	func_ov031_0223bd28((Struct_ov031_02222f44_2*)data_ov031_02290d04.p[3], 0, &var0, &var1);
	var0 = var0 - 8;
	if ((int)var0 > 0x68) {
		int i = 3;
		do {
			Struct_ov031_0224926a_6* e = &data_ov031_0224926a[i];
			func_ov031_0223bbd8((void*)data_ov031_02290d04.p[i], -1, var0, e->hi);
			i++;
		} while (i < 5);
		return;
	}
	var0 = 0x68;
	{
		int i = 3;
		do {
			Struct_ov031_0224926a_6* e = &data_ov031_0224926a[i];
			func_ov031_0223bbd8((void*)data_ov031_02290d04.p[i], -1, var0, e->hi);
			i++;
		} while (i < 5);
	}
	func_ov031_0223e2b8(obj, (int)func_ov031_022370f8);
}
