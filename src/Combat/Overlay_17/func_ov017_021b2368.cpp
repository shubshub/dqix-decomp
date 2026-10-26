#include <globaldefs.h>

struct Struct_ov017_021d83f0_5 { int a; int b; };
extern Struct_ov017_021d83f0_5 data_ov017_021d83f0;
extern "C" void func_ov011_02184760(void);

// USA: func_ov017_021b2368
extern "C" ARM void func_ov017_021b2368(void*) {
	if (data_ov017_021d83f0.b != 0) {
		func_ov011_02184760();
	}
}
