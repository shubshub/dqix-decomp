#include <globaldefs.h>

struct Struct_ov031_0224e598_3 {
	int field0;
	int field4;
};
extern Struct_ov031_0224e598_3 data_ov031_0224e598;

// USA: func_ov031_02211864
extern "C" ARM void func_ov031_02211864(int a, int b) {
	if (b > -10000) b += -10000;
	if (data_ov031_0224e598.field0 != 9) {
		data_ov031_0224e598.field0 = a;
		data_ov031_0224e598.field4 = b;
	}
}
