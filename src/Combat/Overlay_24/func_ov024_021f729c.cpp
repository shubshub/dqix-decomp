#include <globaldefs.h>

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);
extern "C" double _dflt(int);

struct Struct_ov024_021f729c { void* ptr0; char pad[0x18]; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f729c
extern "C" ARM int func_ov024_021f729c(struct Struct_ov024_021f729c* obj) {
	int v = GameObject_GetPartyMemberLevel(obj->ptr0) * 2;
	if (v < 0x23) v = 0x23;
	obj->unknown_1c_ = (float)v;
	obj->unknown_20_ = (float)((0.85) * (_dflt(v)));
	return 1;
}
