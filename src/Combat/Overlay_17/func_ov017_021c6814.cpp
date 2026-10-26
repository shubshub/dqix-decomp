#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6814 {
	unsigned char field0;
	unsigned char field1;
	unsigned char field2;
	unsigned char unknown_3_;
	signed char field4;
	unsigned char pad5;
	unsigned short field6;
	unsigned short field8;
};

struct Struct_ov017_021c6814_2 {
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fielda;
	signed char fieldc;
	unsigned char unknown_9_;
	unsigned char unknown_a_;
	unsigned char unknown_b_;
	unsigned char field10;
	unsigned char flag1:1;
	unsigned char flag2:1;
	unsigned char val:6;
	signed char field12;
	unsigned char pad1;
};

struct Struct_ov017_021c6814_3 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021c6814_2 body;
};

// USA: func_ov017_021c6814
extern "C" ARM void func_ov017_021c6814(unsigned short a, unsigned short b, Struct_ov017_021c6814* src, unsigned char flags, signed char arg4, unsigned char arg5) {
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021c6814_3 buf;
	Struct_ov017_021c6814_2* body = &buf.body;
	GameState* bs = GameState::GetInstance();

	buf.tag = 0x42;
	body->field4 = a;
	body->field6 = b;
	body->unknown_9_ = src->field0;
	body->unknown_a_ = src->field1;
	body->unknown_b_ = src->field2;
	body->field10 = src->unknown_3_;
	body->field8 = src->field6;
	body->fieldc = src->field4;
	body->fielda = src->field8;
	body->flag1 = flags;

	body->val = GameState_GetProtagonistIndex(bs);
	body->field12 = arg4;
	body->flag2 = arg5;

	func_0205e330(p, &buf, 0);
}
