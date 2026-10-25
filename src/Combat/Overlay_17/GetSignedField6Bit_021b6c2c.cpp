#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021b6d60(int a, void* buf);
extern "C" void Party_AddMemberRecord(void* map, void* buf, int c, int d);

// USA: func_ov017_021b6c2c
ARM int GetSignedField6Bit_021b6c2c(int a, int d) {
	char buf[0x23c];
	if (func_ov017_021b6d60(a, buf) == 0) {
		return -1;
	}
	GameState* bs = GameState::GetInstance();
	void* map = GameState_GetParty(bs);
	Party_AddMemberRecord(map, buf, 0, d);
	int v = buf[0];
	v = (v << 26) >> 26;
	return v;
}
