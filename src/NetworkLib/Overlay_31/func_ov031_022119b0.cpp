#include <globaldefs.h>

struct Struct_ov031_0224e5a4 {
	int field0;
	int field4;
};
extern Struct_ov031_0224e5a4 data_ov031_0224e5a4;

// USA: func_ov031_022119b0
extern "C" ARM int func_ov031_022119b0(int *out) {
	if (out != 0) {
		*out = data_ov031_0224e5a4.field4;
	}
	return data_ov031_0224e5a4.field0;
}
