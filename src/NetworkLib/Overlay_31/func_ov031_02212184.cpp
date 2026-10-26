#include <globaldefs.h>

struct Struct_ov031_02212184 {
	int field0;
	unsigned short field4;
	char pad[0x10 - 0x6];
	int field10;
};

struct Struct_ov031_0224e5b4_8 {
	char pad0[4];
	Struct_ov031_02212184* field4;
};

extern Struct_ov031_0224e5b4_8 data_ov031_0224e5b4;
extern "C" void func_ov031_02216698(void);
extern "C" int func_ov031_02216360(void);
extern "C" void func_ov031_022166b4(void);
extern "C" int func_ov031_022130ac(void);

// USA: func_ov031_02212184
extern "C" ARM int func_ov031_02212184(void) {
	Struct_ov031_02212184* q = data_ov031_0224e5b4.field4;
	if (q == NULL) return 1;
	unsigned short state = q->field4;
	if (state == 8) return 1;
	if (state == 1) {
		int sub = q->field10;
		if (sub == 1) {
			func_ov031_02216698();
			data_ov031_0224e5b4.field4->field10 = 5;
			return 0;
		}
		if (sub == 5) {
			int x = func_ov031_02216360();
			if (x == 1) return 0;
			x -= 2;
			if ((unsigned int)x <= 2) {
				func_ov031_022166b4();
			}
		}
		data_ov031_0224e5b4.field4 = 0;
		return 1;
	}
	q->field4 = 5;
	if (func_ov031_022130ac() == 0) return 0;
	data_ov031_0224e5b4.field4 = 0;
	return 1;
}
