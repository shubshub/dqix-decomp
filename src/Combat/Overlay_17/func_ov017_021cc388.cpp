#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x4c0 };
#else
enum { kRegionalFieldOffset = 0x6d0 };
#endif
#include "GameState/GameState.h"

struct SearchStruct;

struct Struct_ov017_021cc388 {
	unsigned char pad0[4];
	signed char ownerId;
	unsigned char count;
	unsigned char ids[3];
	unsigned char kinds[3];
};

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" GameObject* func_0200fee0(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_02190264(unsigned char* ov, int combatantId);
extern "C" void func_ov017_021905b8(unsigned char* ov, int combatantId, int mode);
extern "C" void func_ov017_0218f064(unsigned char* ov, int combatantId, int flag, int c, int d);

extern "C" void func_ov017_021cc4b8(unsigned char combatantId, int tag, int value);
extern "C" ARM void func_020263b0(unsigned char* bits, unsigned int index);

extern "C" void LinkSession_UpdateMemberCount(struct SearchStruct* search);

// USA: func_ov017_021cc388
extern "C" ARM void func_ov017_021cc388(int tag, Struct_ov017_021cc388* group, GameState* battleStruct,
                                        unsigned char* ov, struct SearchStruct* search) {
	if (group->ownerId >= 0) {
		if (group->ownerId != GameState_GetProtagonistIndex(battleStruct)) return;
	}

	unsigned char* bits = *(unsigned char**)(ov + 0x3000 + kRegionalFieldOffset);
	unsigned char count = group->count;
	int var2 = 0x3ff - 0x180;
	int flag, value;
	for (int i = 0; i < count; i++) {
		unsigned char var6 = group->ids[i];
		int id = var6;
		int kind = group->kinds[i];
		if (func_0200ff58(battleStruct, id)) {
			func_ov017_02190264(ov, id);
		} else if (func_0200fee0(battleStruct, id)) {
			func_ov017_021905b8(ov, id, 1);
		}
		if (kind == 0) {
			flag = 0x200;
			value = var2;
		} else if (kind == 1) {
			flag = 0x1000;
			value = 0x3ff;
		}
		func_ov017_0218f064(ov, id, flag, 0, 0);
		func_ov017_021cc4b8(var6, tag, value);
		func_020263b0(bits, id);
	}
	LinkSession_UpdateMemberCount(search);
}
