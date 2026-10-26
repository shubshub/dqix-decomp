#include <globaldefs.h>

struct Struct_ov031_022134b0
{
	unsigned char pad[9];
	unsigned char field9;
};

struct Struct_ov031_0224e5c4_6
{
	unsigned char pad[0xc];
	Struct_ov031_022134b0* unknown_c_;
};

extern Struct_ov031_0224e5c4_6 data_ov031_0224e5c4;

// USA: func_ov031_022134b0
extern "C" ARM int func_ov031_022134b0(void) {
	Struct_ov031_022134b0* p = data_ov031_0224e5c4.unknown_c_;
	if (p != NULL) {
		return p->field9;
	}
	return 0;
}
