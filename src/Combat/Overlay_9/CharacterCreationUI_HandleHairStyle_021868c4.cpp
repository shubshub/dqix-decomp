#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int slot);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
extern "C" void CharacterCreationUI_SwitchTab(unsigned char *self, int tab);
#else
extern "C" ARM void CharacterCreationUI_SwitchTab(unsigned char *self, int tab);
#endif

// Overlay 9, originally func_ov009_021868c4 (USA/EUR 0x021868c4, JPN 0x021879f0)
extern "C" ARM void CharacterCreationUI_HandleHairStyle(CharacterCreationUI* self) {
	unsigned char step = self->step;
	if (step == ChoiceTabStep_Setup) {
		CharacterCreationUI_SetupSlotNavigation(self);
		CharacterCreationUI_LoadSlotLayout(self);
		int sex = self->sex;
		unsigned char choice = self->hairStyle[sex];
		CharacterCreationUI_MoveCursorToSlot(self, choice);
		self->flags |= CreationFlag_StylusRotation;
		self->step = self->step + 1;
		return;
	}
	if (step == ChoiceTabStep_ShowChoice) {
		if (self->flags & CreationFlag_TabLoading) {
			return;
		}
		int sex = self->sex;
		unsigned char choice = self->hairStyle[sex];
		CharacterCreationUI_ApplyChoice(self, choice);
		self->step = self->step + 1;
		return;
	}
	if (step != ChoiceTabStep_Input) {
		return;
	}
	int result = CharacterCreationUI_HandleInput(self);
	if (result == CreationInput_Confirm) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_HairColor);
		return;
	}
	if (result == CreationInput_Back) {
		CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_BodyType);
		return;
	}
	if (result < CreationInput_FirstTabIcon || result > CreationInput_LastTabIcon) {
		return;
	}
	int sex = self->sex;
	int tab = result - CreationInput_TabIcon;
	signed char *furthestState = self->furthestState;
	if (tab > furthestState[sex]) {
		return;
	}
	if (tab == self->state) {
		return;
	}
	CharacterCreationUI_SwitchTab((unsigned char*)self, tab & 0xff);
}
