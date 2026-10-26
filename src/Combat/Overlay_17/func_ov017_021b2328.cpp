#include <globaldefs.h>

struct Struct_ov017_021d83f0_3 { int a; int b; };
extern Struct_ov017_021d83f0_3 data_ov017_021d83f0;
#if defined(jpn)
#define func_ov011_02184740 func_ov011_02185840
#endif
extern "C" void func_ov011_02184740(void*);

// USA: func_ov017_021b2328
extern "C" ARM void func_ov017_021b2328(void*) {
	if (data_ov017_021d83f0.b != 0) {
		func_ov011_02184740((void*)data_ov017_021d83f0.b);
	}
}
