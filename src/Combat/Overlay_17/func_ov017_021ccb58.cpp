#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* buf, int c);

struct Struct_ov017_021ccb58 {
	unsigned char marker;
	char pad1[3];
	unsigned int words[3];
	unsigned short field10;
	unsigned char field12;
};

// USA: func_ov017_021ccb58
extern "C" ARM void func_ov017_021ccb58(int id, int idx) {
	GameState* battle = GameState::GetInstance();
	GameObject* c = func_0200ff1c(battle, id);
	if (!c) return;
	unsigned char* base = (unsigned char*)func_02053c6c((unsigned char*)c);
	if (!base) return;

	void* d = LinkMessageQueue_GetInstance();
	Struct_ov017_021ccb58 buf;
	buf.marker = 0xd;
	buf.field10 = (unsigned short)id;
	buf.field12 = (unsigned char)idx;
	unsigned char i = 0;
	while (i < 3) {
		unsigned int v = *(unsigned int*)(base + (i + idx) * 4 + 0x138);
		buf.words[i] = v;
		i++;
	}
	func_0205e330(d, &buf, 0);
}
