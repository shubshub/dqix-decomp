#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021d0d9c { unsigned char pad0[4]; int val; };

// USA: func_ov017_021d0d9c
extern "C" ARM void func_ov017_021d0d9c(void* unused0, Struct_ov017_021d0d9c* src, GameState* battleStruct) {
	unsigned char* p = (unsigned char*)GameState_GetParty(battleStruct);
	*(int*)(p + 0x2000 + 0xc94) = src->val;
}
