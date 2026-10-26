#include <globaldefs.h>

struct Struct_ov017_021a3b40_2 { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_02160134(void*);

// USA: func_ov017_021b6b5c
extern "C" ARM void func_ov017_021b6b5c(Struct_ov017_021a3b40_2* obj) {
	void* p = obj->f24;
	if (p) func_ov003_02160134(p);
}
