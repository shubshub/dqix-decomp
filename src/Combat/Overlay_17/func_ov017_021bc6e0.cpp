#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(GameState* battleStruct);

struct Struct_02061c04_10 {
	unsigned short unknown_0_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	short unknown_6_;
	unsigned char unknown_8_;
	unsigned short unknown_a_;
	signed char unknown_c_;
	unsigned char unknown_d_;
	float unknown_10_;
};
extern "C" void func_ov017_021cd6d8(Struct_02061c04_10* arg0);

// USA: func_ov017_021bc6e0
extern "C" ARM void func_ov017_021bc6e0(char* self, unsigned char byteArg, int flags) {
	GameState* battleStruct = GameState::GetInstance();
	void* obj2 = Zone3D_GetInstance(battleStruct);
	Src021cd6d8 params;
	params.f0 = 0;
	params.fc = -1;
	params.f2 = 0;
	params.f4 = 0;
	params.f6 = 0;
	params.f8 = 0;
	params.fa = 0;
	params.f10 = 0.0f;
	if (!(flags & 0x800)) {
		params.f0 = *(unsigned short*)obj2;
	}
	var2.unknown_2_ = *(unsigned short*)(arg0 + 0x16);
	var2.unknown_4_ = *(unsigned short*)(arg0 + 0x18);
	var2.unknown_8_ = 0;
	var2.unknown_a_ = *(unsigned short*)(arg0 + 0x1c);
	var2.unknown_6_ = *(short*)(arg0 + 0x52);
	var2.unknown_10_ = var0->GetDayTimer();
	var2.unknown_c_ = arg1;
	func_ov017_021cd6d8(&var2);
}
