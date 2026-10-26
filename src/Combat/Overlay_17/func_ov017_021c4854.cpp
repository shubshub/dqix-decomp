#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
void DispatchWithZeroExtras_02193428(void* a, void* b);

struct Struct_ov017_021c4854 {
	unsigned short unknown_0_;
};

struct Struct_ov017_021c4854_2 {
	int unknown_0_;
	int unknown_4_;
	int unknown_8_;
};

struct Struct_ov017_021c4854_3 {
	unsigned short unknown_0_;
	unsigned char unknown_2_;
	unsigned char unknown_3_;
	unsigned short unknown_4_;
	short unknown_6_;
	short unknown_8_;
	short unknown_a_;
	short unknown_c_;
};

// USA: func_ov017_021c4854
extern "C" ARM void func_ov017_021c4854(struct Obj021c4854* obj, unsigned char byteArg, unsigned short shortArg, struct Arr3_021c4854* arr, short arg5, unsigned char arg6) {
	unsigned short v0 = obj->field0;
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0x37;
	Src021c4854* s = (Src021c4854*)(buf + 4);
	s->f0 = v0;
	s->f2 = byteArg;
	s->f4 = shortArg;
	s->f6 = arr->a >> 5;
	s->f8 = arr->b >> 5;
	s->fa = arr->c >> 5;
	s->fc = arg5;
	s->f3 = arg6;
	func_0205e330(p, buf, 0);

	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetLeader();
	((Object3D*)((unsigned char*)c))->EnableFlag(0x4000000);
	DispatchWithZeroExtras_02193428(c, 0);
}
