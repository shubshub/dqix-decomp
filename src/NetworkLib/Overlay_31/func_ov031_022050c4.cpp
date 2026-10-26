#include <globaldefs.h>

struct Struct_ov031_0224e200 {
	int field0;
	char pad[0x14];
	int field18;
	char pad2[4];
	int field20;
};
extern Struct_ov031_0224e200 data_ov031_0224e200;

struct Struct_ov031_022050c4 {
	char pad[0x1c];
	void (*field1c)(int);
};
extern void* data_ov031_022496a4;

// USA: func_ov031_022050c4
extern "C" ARM int func_ov031_022050c4(void) {
	if (data_ov031_0224e200.field20 < data_ov031_0224e200.field18) return -1;
	((Struct_ov031_022050c4*)data_ov031_022496a4)->field1c(data_ov031_0224e200.field0);
	data_ov031_0224e200.field0 = 0;
	return 0;
}
