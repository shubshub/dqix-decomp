#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021ce658 {
	char pad0[4];
	signed char f4;
	signed char unknown_5_;
	unsigned char unknown_6_;
};

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_020e3b8c(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8);

// USA: func_ov017_021ce658
extern "C" ARM void func_ov017_021ce658(void* unused0, struct Struct_ov017_021ce658* entry, GameState* battle, char* mgr) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	signed char f4 = entry->f4;
	GameObject* c = func_0200ff1c(battle, f4);
	if (c == NULL) return;

	char* field150 = (char*)func_02053c6c((unsigned char*)c);
	if (field150 == 0) return;

	int field950 = *(int*)(field150 + regionalOffset0);
	signed char var4 = entry->unknown_5_;
	unsigned short var5 = *(unsigned short*)(field150 + (field950 << 1) + 0x100 + 0x6c);
	if (var4 < 0) return;

	if (var4 == 0) {
		func_020e3b8c(mgr, f4, var5, field950, 0, 0, 0, entry->unknown_6_);
	} else {
		func_020e3b8c(mgr, f4, var4, field950, 0, 0, 0, entry->unknown_6_);
	}
}
