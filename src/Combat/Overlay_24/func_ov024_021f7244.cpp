#include <globaldefs.h>

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov024_021f7244 { void* obj; char pad[0x10]; float unknown_14_; float unknown_18_; float f1c; float f20; };

// USA: func_ov024_021f7244
extern "C" ARM int func_ov024_021f7244(struct Struct_ov024_021f7244* s) {
	GameObject_GetPartyMemberLevel(s->obj);
	s->f1c = s->unknown_14_ / 4.0f + 5.0f;
	s->f20 = s->unknown_18_ / 4.0f + 5.0f;
	return 1;
}
