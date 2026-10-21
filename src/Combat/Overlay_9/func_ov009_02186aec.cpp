#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int val);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int val);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char *self, int val);
#else
ARM void CharacterCreationUI_SwitchTab(unsigned char *self, int val);
#endif

// USA: func_ov009_02186aec  (semantic: AdvanceStatStep_02186aec)
extern "C" ARM void func_ov009_02186aec(CharacterCreationUI* self) {
	unsigned char step = self->step;
	if (step == 0) {
		CharacterCreationUI_SetupSlotNavigation(self);
		CharacterCreationUI_LoadSlotLayout(self);
		int idx = self->sex;
		unsigned char val = self->eyeColor[idx];
		CharacterCreationUI_MoveCursorToSlot(self, val);
		self->flags |= 1;
		self->step = self->step + 1;
		return;
	}
	if (step == 1) {
		if (self->flags & 0x80) {
			return;
		}
		int idx = self->sex;
		unsigned char val = self->eyeColor[idx];
		CharacterCreationUI_ApplyChoice(self, val);
		self->step = self->step + 1;
		return;
	}
	if (step != 2) {
		return;
	}
	int result = CharacterCreationUI_HandleInput(self);
	if (result == -2) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, 7);
		return;
	}
	if (result == -3) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, 5);
		return;
	}
	if (result < 0x65 || result > 0x6c) {
		return;
	}
	int idx2 = self->sex;
	int v = result - 0x64;
	signed char *arr = self->furthestState;
	if (v > arr[idx2]) {
		return;
	}
	if (v == self->state) {
		return;
	}
	CharacterCreationUI_SwitchTab((unsigned char*)self, v & 0xff);
}
