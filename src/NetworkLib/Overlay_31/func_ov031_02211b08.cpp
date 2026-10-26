#include <globaldefs.h>

struct Struct_ov031_0224e5a4_4 {
	int field0;
	int field4;
};

extern Struct_ov031_0224e5a4_4 data_ov031_0224e5a4;

// USA: func_ov031_02211b08
extern "C" ARM void func_ov031_02211b08(int a, int b) {
	if (data_ov031_0224e5a4.field0 != 9) {
		data_ov031_0224e5a4.field0 = a;
		data_ov031_0224e5a4.field4 = b;
	}
}
