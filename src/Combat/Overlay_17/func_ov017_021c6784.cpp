#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c6784 {
	unsigned char pad0[4];
	int field4;
	unsigned short field8;
	unsigned short fielda;
	unsigned char fieldc;
	unsigned char unknown_d_;
	unsigned char unknown_e_;
};

struct Struct_ov017_021c6784_2 {
	unsigned char f0;
	unsigned char f1;
	unsigned short f2;
	int f4;
};

struct Struct_ov017_021c6784_3 {
	unsigned char pad0[0x4c];
	Struct_ov017_021c6784_2 items[1];
};

// USA: func_ov017_021c6784
extern "C" ARM void func_ov017_021c6784(int unused0, Struct_ov017_021c6784* src, GameState* battleStruct, char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* table = *(void**)(base + 0x3000 + regionalOffset0);

	void* fieldObj = func_ov017_021b8478(table);
	if (!fieldObj) return;

	void* state = func_ov017_021b8470(table);
	if (!state) return;

	int value = GameState_GetProtagonistIndex(battleStruct);
	if (*((signed char*)fieldObj + 0x2a) == value) return;
	if (*(unsigned short*)((char*)fieldObj + 0x8) != src->field8) return;

	Struct_ov017_021c6784_3* holder = (Struct_ov017_021c6784_3*)((char*)state + 0x1b0 + 0x8000);
	Struct_ov017_021c6784_2* entry = &holder->items[src->unknown_e_];
	entry->f2 = src->fielda;
	entry->f1 = src->fieldc;
	entry->f0 = src->unknown_d_;
	entry->f4 = src->field4;
}
