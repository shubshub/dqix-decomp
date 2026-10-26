#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021cbff4_14104 = 0x3508, Enum_ov017_021cbff4_22312 = 0x54c8 };
#else
enum { Enum_ov017_021cbff4_14104 = 0x3718, Enum_ov017_021cbff4_22312 = 0x5728 };
#endif

#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);

struct Struct_ov017_021cbff4 {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Struct_ov017_021cbff4_2 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
};

// USA: func_ov017_021cbff4
extern "C" ARM void func_ov017_021cbff4(int unused0, Struct_ov017_021cbff4_2* src, int arg2, unsigned char* obj) {
	unsigned char* h = *(unsigned char**)(obj + Enum_ov017_021cbff4_14104);
	if (!h || h[3] == 0) return;
	Struct_ov017_021cbff4* r = (Struct_ov017_021cbff4*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	unsigned char* bs = (unsigned char*)GameState::GetInstance();
	bs[Enum_ov017_021cbff4_22312] = src->field6 != 0 ? 1 : 0;
}
