#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov017_021ca2d8 { unsigned char pad[4]; unsigned short h4; unsigned short h6; };

struct Struct_ov017_021b88d0_3;
extern "C" void func_ov017_021b88d0(Struct_ov017_021b88d0_3*, int combatantId, int key);

// USA: func_ov017_021ca2d8
extern "C" ARM void func_ov017_021ca2d8(int unused0, Struct_ov017_021ca2d8* src, int arg2, GameResources* ov) {
	Struct_ov017_021b88d0_3* battle = (Struct_ov017_021b88d0_3*)ov->unknown_ptr_3718;
	func_ov017_021b88d0(battle, src->h4, src->h6);
}
