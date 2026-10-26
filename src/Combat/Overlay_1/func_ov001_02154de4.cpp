#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_ov017_021d035c(unsigned char a, unsigned char b, unsigned char c);
extern "C" int func_ov001_02154c64(void* a);
extern "C" void func_ov001_021539d8(void* a);
extern "C" int func_ov001_02153948(unsigned short a);

struct Struct_ov001_02154de4 {
	unsigned char pad0[0x4a];
	unsigned short unknown_4a_;
#if defined(jpn)
	unsigned char pad1[0x104 - 0x4c];
#else
	unsigned char pad1[0x108 - 0x4c];
#endif
	unsigned char unknown_108_;
};

// USA: func_ov001_02154de4
extern "C" ARM int func_ov001_02154de4(struct Struct_ov001_02154de4* self) {
	if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
		GameState* bs = GameState::GetInstance();
		unsigned char v = GameState_GetLeaderIndex(bs);
		func_ov017_021d035c(1, v & 0xff, self->unknown_108_);
	}
	if (func_ov001_02154c64(self) != 0) {
		return 0x11;
	}
	func_ov001_021539d8(self);
	func_ov001_02153948(self->unknown_4a_);
	return 4;
}
