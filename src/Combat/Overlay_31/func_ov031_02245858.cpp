#include <globaldefs.h>

struct Struct_ov031_02291f24 { unsigned char b0; unsigned char pad[0x13]; int field14; };
extern struct Struct_ov031_02291f24 data_ov031_02291f24;

// USA: func_ov031_02245858
extern "C" ARM void func_ov031_02245858(int a, unsigned char b) {
	data_ov031_02291f24.field14 = a;
	data_ov031_02291f24.b0 = b;
}
