#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2* h, int index, unsigned int* arg2, unsigned int* arg3);

struct Struct_ov031_0224926a { unsigned short lo; unsigned short hi; };
extern Struct_ov031_0224926a data_ov031_0224926a[];

struct Struct_ov031_022372b0 { void* items[5]; int f14; };
struct Struct_ov031_02290d04_15 { char pad[4]; Struct_ov031_022372b0* p; };
extern Struct_ov031_02290d04_15 data_ov031_02290d04;

extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2c0(int, void*);
extern "C" void func_ov031_0223ba20(void*);
extern "C" void func_ov031_0223cf70(void*);
extern void* data_ov031_02290d08;

// USA: func_ov031_022372b0
extern "C" ARM void func_ov031_022372b0(void* obj) {
	int hi;
	unsigned int lo;
	func_ov031_0223bd28((Struct_ov031_02222f44_2*)data_ov031_02290d04.p->items[0], 0, (unsigned int*)&hi, &lo);
	hi -= 8;
	int i = 0;
	do {
		Struct_ov031_0224926a* p = &data_ov031_0224926a[i];
		void* item = data_ov031_02290d04.p->items[i];
		unsigned short v = p->hi;
		func_ov031_0223bbd8(item, -1, hi, v);
		i++;
	} while (i < 5);
	if (hi > 0x1d6) {
		return;
	}
	if (hi < 0x100) {
		return;
	}
	func_ov031_0223e2c0(0, obj);
	int j = 0;
	do {
		void* item = data_ov031_02290d04.p->items[j];
		func_ov031_0223ba20(item);
		j++;
	} while (j < 5);
	func_ov031_0223cf70(&data_ov031_02290d08);
}
