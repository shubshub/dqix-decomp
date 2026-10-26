#include <globaldefs.h>

struct Struct_ov017_021d3eb4 { unsigned char pad[4]; int w4; };
extern int data_ov017_021d847c;

// USA: func_ov017_021d3eb4
extern "C" ARM void func_ov017_021d3eb4(int unused0, Struct_ov017_021d3eb4* src) {
	data_ov017_021d847c = src->w4;
}
