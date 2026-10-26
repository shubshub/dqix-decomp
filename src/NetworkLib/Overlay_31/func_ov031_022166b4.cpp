#include <globaldefs.h>

extern "C" void func_ov031_02211b98(int a, void *p, int c);

struct Struct_ov031_0224e5dc_4 {
	void *field0;
	void *field4;
};
extern struct Struct_ov031_0224e5dc_4 data_ov031_0224e5dc;

// USA: func_ov031_022166b4
extern "C" ARM void func_ov031_022166b4(void) {
	if (data_ov031_0224e5dc.field4 != 0) {
		func_ov031_02211b98(1, data_ov031_0224e5dc.field4, 0);
		data_ov031_0224e5dc.field4 = 0;
	}
	if (data_ov031_0224e5dc.field0 != 0) {
		func_ov031_02211b98(1, data_ov031_0224e5dc.field0, 0);
		data_ov031_0224e5dc.field0 = 0;
	}
}
