#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_02193428(void* a, void* b);

struct Struct_ov017_021c4854 {
	unsigned short field0;
};

struct Struct_ov017_021c4854_2 {
	int a;
	int b;
	int c;
};

struct Struct_ov017_021c4854_3 {
	unsigned short f0;
	unsigned char f2;
	unsigned char f3;
	unsigned short f4;
	short unknown_6_;
	short f8;
	short fa;
	short fc;
};

// USA: func_ov017_021c4854
extern "C" ARM void func_ov017_021c4854(struct Struct_ov017_021c4854* obj, unsigned char arg1, unsigned short arg2, struct Struct_ov017_021c4854_2* arr, short arg4, unsigned char arg5) {
	unsigned short v0 = obj->field0;
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0x37;
	Struct_ov017_021c4854_3* s = (Struct_ov017_021c4854_3*)(buf + 4);
	s->f0 = v0;
	s->f2 = arg1;
	s->f4 = arg2;
	s->unknown_6_ = arr->a >> 5;
	s->f8 = arr->b >> 5;
	s->fa = arr->c >> 5;
	s->fc = arg4;
	s->f3 = arg5;
	func_0205e330(p, buf, 0);

	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetLeader();
	((Object3D*)((unsigned char*)c))->EnableFlag(0x4000000);
	func_ov017_02193428(c, 0);
}
