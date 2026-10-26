#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

struct Struct_ov014_021882d4 {
	unsigned char pad0[0x17a];
	unsigned char unknown_17a_;
	unsigned char unknown_17b_;
};

// USA: func_ov014_021882d4
extern "C" ARM void func_ov014_021882d4(struct Struct_ov014_021882d4* r4) {
	int val = (int)GameState::GetInstance()->GetResources();
	if (r4->unknown_17b_ == 0) {
		SetBrightness((GameResources*)val, -16, 8);
		r4->unknown_17b_++;
		return;
	}
	if (r4->unknown_17b_ != 1) return;
	if (!IsBrightnessTransitionActive((GameResources*)val)) {
		r4->unknown_17a_ = 6;
		r4->unknown_17b_ = 0;
	}
}
