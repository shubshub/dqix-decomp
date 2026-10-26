#include <globaldefs.h>

extern "C" void func_ov027_021dcd20(void);

struct Struct_ov031_02238db4 { unsigned short h0; unsigned short h2; unsigned char pad[8]; unsigned short hc; };
struct Struct_ov031_02290d14 { struct Struct_ov031_02238db4* field0; };
extern struct Struct_ov031_02290d14 data_ov031_02290d14;

// USA: func_ov031_02238db4
extern "C" ARM void func_ov031_02238db4(void) {
	struct Struct_ov031_02238db4* p = data_ov031_02290d14.field0;
	if (p->h0 == 4 && p->h2 == p->hc) {
		func_ov027_021dcd20();
	}
}
