#include <globaldefs.h>

struct Struct_ov017_021a4368_3 { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_02160240(void*);

// USA: func_ov017_021b6b74
extern "C" ARM void func_ov017_021b6b74(Struct_ov017_021a4368_3* obj) {
	void* p = obj->f24;
	if (p) func_ov003_02160240(p);
}
