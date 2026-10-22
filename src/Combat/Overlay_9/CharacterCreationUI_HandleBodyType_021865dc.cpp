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

// Overlay 9, originally func_ov009_021865dc (USA/EUR 0x021865dc, JPN 0x02187708)
extern "C" ARM void CharacterCreationUI_HandleBodyType(CharacterCreationUI* self) {
	unsigned char step = self->step;
	if (step == 0) {
		CharacterCreationUI_SetupSlotNavigation(self);
		CharacterCreationUI_LoadSlotLayout(self);
		int idx = self->sex;
		unsigned char val = self->bodyType[idx];
		CharacterCreationUI_MoveCursorToSlot(self, val);
		self->flags |= 1;
		self->step = self->step + 1;
		return;
	}
	if (step == 1) {
		if (self->flags & CreationFlag_TabLoading) {
			return;
		}
		int idx = self->sex;
		unsigned char val = self->bodyType[idx];
		CharacterCreationUI_ApplyChoice(self, val);
		self->step = self->step + 1;
		return;
	}
	if (step != 2) {
		return;
	}
	int result = CharacterCreationUI_HandleInput(self);
	if (result == CreationInput_Confirm) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_HairStyle);
		return;
	}
	if (result == CreationInput_Back) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Gender);
		return;
	}
	if (result < CreationInput_FirstTabIcon || result > CreationInput_LastTabIcon) {
		return;
	}
	int idx2 = self->sex;
	int v = result - CreationInput_TabIcon;
	signed char *arr = self->furthestState;
	if (v > arr[idx2]) {
		return;
	}
	if (v == self->state) {
		return;
	}
	CharacterCreationUI_SwitchTab((unsigned char*)self, v & 0xff);
}
