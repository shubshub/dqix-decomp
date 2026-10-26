#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Element0x318_02028bac { unsigned char data[0x318]; };
extern "C" struct Element0x318_02028bac* ZoneRecords_GetAt(struct Element0x318_02028bac* base, int index);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" void func_020733d8(void* elem, int mode);

struct Struct_ov017_021a205c { unsigned short pad0 : 3; unsigned short unknown_0_3_ : 1; unsigned short pad4 : 12; };

// USA: func_ov017_021a205c
extern "C" ARM void func_ov017_021a205c(GameResources*) {
	GameState* battleStruct = GameState::GetInstance();
	struct Element0x318_02028bac* table = (struct Element0x318_02028bac*)ZoneRecords_GetInstance();
	(int)BackgroundLoader::GetInstance();
	for (int i = 0; i < 4; i++) {
		battleStruct->GetPartyMemberByIndex(i);
		struct Element0x318_02028bac* elem = ZoneRecords_GetAt(table, i);
		struct Struct_ov017_021a205c* flags = (struct Struct_ov017_021a205c*)((unsigned char*)elem + 2);
		if (flags->unknown_0_3_) {
			func_020733d8(elem, 0);
		}
	}
}
