#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* buf, int c);

struct Struct_ov017_021ccb58 {
	unsigned char unknown_0_;
	char unknown_1_[3];
	unsigned int unknown_4_[3];
	unsigned short unknown_10_;
	unsigned char unknown_12_;
};

// USA: func_ov017_021ccb58
extern "C" ARM void func_ov017_021ccb58(int arg0, int arg1) {
	GameState* var0 = GameState::GetInstance();
	GameObject* var1 = func_0200ff1c(var0, arg0);
	if (!var1) return;
	unsigned char* var2 = (unsigned char*)func_02053c6c((unsigned char*)var1);
	if (!var2) return;

	void* d = LinkMessageQueue_GetInstance();
	Dst021ccb58 buf;
	buf.marker = 0xd;
	buf.field10 = (unsigned short)id;
	buf.field12 = (unsigned char)idx;
	unsigned char i = 0;
	while (i < 3) {
		unsigned int v = *(unsigned int*)(base + (i + idx) * 4 + 0x138);
		buf.words[i] = v;
		i++;
	}
	func_0205e330(var3, &var4, 0);
}
