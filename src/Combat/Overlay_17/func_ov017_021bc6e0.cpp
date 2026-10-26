#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(GameState* battleStruct);

struct Struct_02061c04_10 {
	unsigned short f0;
	unsigned short f2;
	unsigned short f4;
	short unknown_6_;
	unsigned char f8;
	unsigned short fa;
	signed char fc;
	unsigned char pad;
	float f10;
};
extern "C" void func_ov017_021cd6d8(Struct_02061c04_10* src);

// USA: func_ov017_021bc6e0
extern "C" ARM void func_ov017_021bc6e0(char* self, unsigned char arg1, int flags) {
	GameState* battleStruct = GameState::GetInstance();
	void* obj2 = Zone3D_GetInstance(battleStruct);
	Struct_02061c04_10 params;
	params.f0 = 0;
	params.fc = -1;
	params.f2 = 0;
	params.f4 = 0;
	params.unknown_6_ = 0;
	params.f8 = 0;
	params.fa = 0;
	params.f10 = 0.0f;
	if (!(flags & 0x800)) {
		params.f0 = *(unsigned short*)obj2;
	}
	params.f2 = *(unsigned short*)(self + 0x16);
	params.f4 = *(unsigned short*)(self + 0x18);
	params.f8 = 0;
	params.fa = *(unsigned short*)(self + 0x1c);
	params.unknown_6_ = *(short*)(self + 0x52);
	params.f10 = battleStruct->GetDayTimer();
	params.fc = arg1;
	func_ov017_021cd6d8(&params);
}
