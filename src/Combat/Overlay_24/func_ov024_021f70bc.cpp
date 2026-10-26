#include <globaldefs.h>

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov024_021f70bc { void* obj; char pad[0x18]; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f70bc
extern "C" ARM int func_ov024_021f70bc(struct Struct_ov024_021f70bc* s) {
	int idx = GameObject_GetPartyMemberLevel(s->obj) * 2;
	s->unknown_1c_ = (float)(idx + 125);
	s->unknown_20_ = (float)(idx + 125) * 0.85f;
	return 1;
}
