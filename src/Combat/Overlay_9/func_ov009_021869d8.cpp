#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int val);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int val);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(unsigned char *arg0, int arg1);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" ARM void func_ov009_021855dc(unsigned char *arg0, int arg1);
#endif

// USA: func_ov009_021869d8  (semantic: AdvanceStatStep_021869d8)
extern "C" ARM void func_ov009_021869d8(CharacterCreationUI* self) {
	unsigned char step = self->step;
	if (step == 0) {
		CharacterCreationUI_SetupSlotNavigation(self);
		CharacterCreationUI_LoadSlotLayout(self);
		int idx = self->sex;
		unsigned char val = self->hairColor[idx];
		func_ov009_02188e70(self, val);
		self->flags |= 1;
		self->step = self->step + 1;
		return;
	}
	if (var0 == 1) {
		if (arg0->unknown_d9c_ & 0x80) {
			return;
		}
		int idx = self->sex;
		unsigned char val = self->hairColor[idx];
		CharacterCreationUI_ApplyChoice(self, val);
		self->step = self->step + 1;
		return;
	}
	if (var0 != 2) {
		return;
	}
	int var5 = func_ov009_02188ee8(arg0);
	if (var5 == -2) {
		func_ov009_021855dc((unsigned char*)arg0, 5);
		return;
	}
	if (var5 == -3) {
		func_ov009_021855dc((unsigned char*)arg0, 3);
		return;
	}
	if (var5 < 0x65 || var5 > 0x6c) {
		return;
	}
	int var6 = arg0->unknown_da3_;
	int var7 = var5 - 0x64;
	signed char *var8 = arg0->unknown_da0_;
	if (var7 > var8[var6]) {
		return;
	}
	if (var7 == arg0->unknown_c58_) {
		return;
	}
	func_ov009_021855dc((unsigned char*)arg0, var7 & 0xff);
}
