#include <globaldefs.h>
#include "GameState/GameState.h"



#if defined(jpn)
enum { Enum_ov003_021669f0_1152 = 0x2a8 };
#else
enum { Enum_ov003_021669f0_1152 = 0x480 };
#endif

extern "C" void* GameState_GetParty(GameState*);
extern "C" int func_ov003_02166a90(char* self, int val);

struct Struct_02086a04;
extern "C" int func_02086a04(struct Struct_02086a04* c, int id);

extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

// USA: func_ov003_021669f0
extern "C" ARM int func_ov003_021669f0(char* self) {
	GameState* bs;
	void* p2a04;
	int r;
	GameObject* c;

	if (*(short*)(self + Enum_ov003_021669f0_1152) < 0) return 1;

	bs = GameState::GetInstance();
	p2a04 = GameState_GetParty(bs);
	r = func_ov003_02166a90(self, *(short*)(self + Enum_ov003_021669f0_1152));
	if (r == 0) return 0;
	if (r == 1) {
		func_02086a04((struct Struct_02086a04*)p2a04, (signed char)*(short*)(self + Enum_ov003_021669f0_1152));
		void* p = Scenario_GetInstance();
		Scenario_SetFlag(p, (unsigned char*)p + 0x8c, 0x784, 1);
	}

	c = bs->GetProtagonist();
	if (c != NULL) {
		GameObject_DisableControl((struct Obj020397cc*)c, 1);
	}
	return 1;
}
