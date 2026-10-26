#include <globaldefs.h>

struct Struct_ov017_021a3ddc { unsigned char pad[0x6ac]; void* unknown_6ac_; };

extern "C" void func_ov000_02160b54(void*);

// USA: func_ov017_021b8408
extern "C" ARM void func_ov017_021b8408(Struct_ov017_021a3ddc* obj) {
	void* p = obj->unknown_6ac_;
	if (p) func_ov000_02160b54(p);
}
