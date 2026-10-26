#include <globaldefs.h>

struct Struct_ov017_021a4368 { unsigned char pad[0x20]; void* f20; };

extern "C" void func_ov008_0218946c(char*);

// USA: func_ov017_021a99b0
extern "C" ARM void func_ov017_021a99b0(Struct_ov017_021a4368* obj) {
	void* p = obj->f20;
	if (p) func_ov008_0218946c((char*)p);
}
