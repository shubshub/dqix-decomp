#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
struct Struct_ov023_021f5228 { char pad[0x144]; char *unknown_150_; };
#else
struct Struct_ov023_021f5228 { char pad[0x150]; char *unknown_150_; };
#endif
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_020dd11c(unsigned int a, unsigned int b);

// USA: func_ov023_021f5228
extern "C" ARM int func_ov023_021f5228(int id) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	GameState *bs = GameState::GetInstance();
	struct Struct_ov023_021f5228 *combatant = (struct Struct_ov023_021f5228*)func_0200ff1c(bs, id);
	if (!combatant) return 0;
	int field150 = func_02053c6c((unsigned char*)combatant);
	if (!field150) return 0;
	int val = *(int*)(combatant->unknown_150_ + regionalOffset0);
	unsigned int byteVal = val & 0xff;
	for (int i = 0; i < 5; i++) {
		int idx = func_020dd11c(byteVal, i & 0xff);
		unsigned char *base = (unsigned char*)(field150 + idx);
		if (base[0x464] < 0x64) return 1;
	}
	return 0;
}
