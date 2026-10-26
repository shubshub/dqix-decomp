#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_022393e4(int v);
extern "C" ARM int func_020d5898(int a, int b, int c, int d, unsigned short e, unsigned short f);
extern "C" void func_ov031_022397bc(void);

struct Struct_ov031_02239724 { unsigned char pad[0x40]; int field40; };
struct Struct_ov031_02290d18_11 { unsigned char pad[4]; Struct_ov031_02239724* field4; };
extern Struct_ov031_02290d18_11 data_ov031_02290d18;

// USA: func_ov031_02239724
extern "C" ARM int func_ov031_02239724(void) {
	if ((unsigned int)(data_ov031_02290d18.field4->field40 - 4) <= 2) {
		return 1;
	}
	func_ov031_02239368(4);
	char* base = (char*)data_ov031_02290d18.field4;
	int e = *(int*)(base + 0x1000 + 0x2a0);
	int c = (unsigned short)*(int*)(base + 0x1000 + 0x2a4);
	int r = func_020d5898((int)func_ov031_022397bc, (int)(base + 0x1060), c, (int)(base + 0xf80), (unsigned short)e, 1);
	if (r == 2) {
		return 1;
	}
	func_ov031_022393e4(r);
	return 0;
}
