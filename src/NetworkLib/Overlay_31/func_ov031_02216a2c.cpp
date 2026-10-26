#include <globaldefs.h>

typedef void (*Type_ov031_02216a2c)(void *a, void *b, int c);

struct Struct_ov031_0224e5e8_4 {
	char pad[8];
	void *field8;
};
extern struct Struct_ov031_0224e5e8_4 data_ov031_0224e5e8;
extern void *data_ov031_02249ba8;
extern "C" void func_ov031_022183b4(void);

// USA: func_ov031_02216a2c
extern "C" ARM void func_ov031_02216a2c(void) {
	void *base = data_ov031_0224e5e8.field8;
	if (base == 0) return;
	char *var1 = (char*)base + 0x1000;
	int flag = *(int*)(var1 + 0x314);
	Type_ov031_02216a2c fp = *(Type_ov031_02216a2c*)(var1 + 0x210);
	if (flag != 0) {
		func_ov031_022183b4();
	}
	fp(&data_ov031_02249ba8, data_ov031_0224e5e8.field8, 0);
	data_ov031_0224e5e8.field8 = 0;
}
