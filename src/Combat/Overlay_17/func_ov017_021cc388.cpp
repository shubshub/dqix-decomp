#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021cc388_1744 = 0x4c0 };
#else
enum { Enum_ov017_021cc388_1744 = 0x6d0 };
#endif
#include "GameState/GameState.h"

struct Struct_0202b2f0;

struct Struct_ov017_021cc388 {
	unsigned char unknown_0_[4];
	signed char unknown_4_;
	unsigned char unknown_5_;
	unsigned char unknown_6_[3];
	unsigned char unknown_9_[3];
};

int GameState_GetProtagonistIndex(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
GameObject* GetCombatantWithFlag0x200_0200fee0(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_02190264(unsigned char* arg0, int arg1);
extern "C" void func_ov017_021905b8(unsigned char* arg0, int arg1, int arg2);
extern "C" void func_ov017_0218f064(unsigned char* arg0, int arg1, int arg2, int arg3, int arg4);

extern "C" void func_ov017_021cc4b8(unsigned char arg0, int arg1, int arg2);
extern "C" ARM void func_020263b0(unsigned char* arg0, unsigned int arg1);

extern "C" void func_0202c288(struct Struct_0202b2f0* arg0);

// USA: func_ov017_021cc388  (semantic: EnqueueGroupEventsAndSetBits_021cc388)
extern "C" ARM void func_ov017_021cc388(int tag, Group021cc388* group, GameState* battleStruct,
                                        unsigned char* ov, struct SearchStruct* search) {
	if (group->ownerId >= 0) {
		if (group->ownerId != GameState_GetProtagonistIndex(battleStruct)) return;
	}

	unsigned char* var0 = *(unsigned char**)(arg3 + 0x3000 + Enum_ov017_021cc388_1744);
	unsigned char var1 = arg1->unknown_5_;
	int var2 = 0x3ff - 0x180;
	int var3, var4;
	for (int var5 = 0; var5 < var1; var5++) {
		unsigned char var6 = arg1->unknown_6_[var5];
		int var7 = var6;
		int var8 = arg1->unknown_9_[var5];
		if (func_0200ff58(arg2, var7)) {
			func_ov017_02190264(arg3, var7);
		} else if (func_0200fee0(arg2, var7)) {
			func_ov017_021905b8(arg3, var7, 1);
		}
		if (var8 == 0) {
			var3 = 0x200;
			var4 = var2;
		} else if (var8 == 1) {
			var3 = 0x1000;
			var4 = 0x3ff;
		}
		func_ov017_0218f064(arg3, var7, var3, 0, 0);
		func_ov017_021cc4b8(var6, arg0, var4);
		func_020263b0(var0, var7);
	}
	func_0202c288(arg4);
}
