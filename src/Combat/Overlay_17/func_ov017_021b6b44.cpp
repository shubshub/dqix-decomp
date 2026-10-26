#include <globaldefs.h>

struct Struct_ov017_021a3ddc_2 { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_021600b8(void*);

// USA: func_ov017_021b6b44
extern "C" ARM void func_ov017_021b6b44(Struct_ov017_021a3ddc_2* obj) {
	void* p = obj->f24;
	if (p) func_ov003_021600b8(p);
}
