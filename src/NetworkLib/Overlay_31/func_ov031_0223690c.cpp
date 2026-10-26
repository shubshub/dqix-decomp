#include <globaldefs.h>

struct Struct_ov031_02222ce4;
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);

struct Struct_ov031_0224926a { unsigned short lo; unsigned short hi; };
extern Struct_ov031_0224926a data_ov031_0224926a[];
extern unsigned char data_ov031_0224924c[][5];
extern unsigned char data_ov031_0224925b[][5];

struct Struct_ov031_0223690c { void* items[5]; void* f14; int f18; };
struct Struct_ov031_02290d04 { char pad[4]; Struct_ov031_0223690c* p; };
extern Struct_ov031_02290d04 data_ov031_02290d04;

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void* func_ov031_0223be70(int, int, int);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223bb58(void* obj, int idx, int a, int b);
extern "C" void* func_ov031_022373b4(int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02236a08(void* obj);

// USA: func_ov031_0223690c
extern "C" ARM void func_ov031_0223690c(int idx) {
	data_ov031_02290d04.p = (Struct_ov031_0223690c*)func_ov031_0223cf4c(0x1c, 4);
	unsigned char* a = data_ov031_0224924c[idx];
	unsigned char* b = data_ov031_0224925b[idx];
	int i = 0;
	do {
		data_ov031_02290d04.p->items[i] = func_ov031_0223be70(1, *a++, 1);
		func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02290d04.p->items[i], -1, 0);
		Struct_ov031_0224926a* p = &data_ov031_0224926a[i];
		func_ov031_0223bbd8(data_ov031_02290d04.p->items[i], -1, -42, p->hi);
		func_ov031_0223bb58(data_ov031_02290d04.p->items[i], -1, 0, *b++);
		i++;
	} while (i < 5);
	data_ov031_02290d04.p->f14 = func_ov031_0223e218(0, (void*)func_ov031_02236a08, 0, 0x78);
	func_ov031_022373b4(idx);
	func_ov031_02236878(0xd);
}
