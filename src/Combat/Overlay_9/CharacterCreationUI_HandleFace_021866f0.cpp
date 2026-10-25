#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int slot);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);
#else
ARM void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);
#endif

int Camera_EasePositionTo(struct Camera* obj, int a, int b);
void Camera_EaseTargetTo(struct Camera* obj, int a, int b);

extern Vector3fix CharacterCreationUI_faceTabCameraPosition;
extern Vector3fix CharacterCreationUI_faceTabCameraTarget;
extern Vector3fix CharacterCreationUI_faceTabExitCameraPosition;
extern Vector3fix CharacterCreationUI_faceTabExitCameraTarget;

// Overlay 9, originally func_ov009_021866f0 (USA/EUR 0x021866f0, JPN 0x0218781c)
extern "C" ARM void CharacterCreationUI_HandleFace(CharacterCreationUI* self) {
    unsigned char step = self->step;
    if (step == ChoiceTabStep_Setup) {
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        int sex = self->sex;
        unsigned char choice = self->faceStyle[sex];
        CharacterCreationUI_MoveCursorToSlot(self, choice);

        Vector3fix position = CharacterCreationUI_faceTabCameraPosition;
        Vector3fix target = CharacterCreationUI_faceTabCameraTarget;
        Camera_EasePositionTo((struct Camera*)self->camera, (int)&position, CreationCamera_EaseSteps);
        Camera_EaseTargetTo((struct Camera*)self->camera, (int)&target, CreationCamera_EaseSteps);

        self->flags |= CreationFlag_StylusRotation;
        self->step = self->step + 1;
        return;
    }
    if (step == ChoiceTabStep_ShowChoice) {
        if (self->flags & CreationFlag_TabLoading) {
            return;
        }
        int sex = self->sex;
        unsigned char choice = self->faceStyle[sex];
        CharacterCreationUI_ApplyChoice(self, choice);
        self->step = self->step + 1;
        return;
    }
    if (step != ChoiceTabStep_Input) {
        return;
    }

    int result = CharacterCreationUI_HandleInput(self);
    int leavingTab = 0;
    if (result == CreationInput_Confirm) {
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_SkinColor);
        leavingTab = 1;
    } else if (result == CreationInput_Back) {
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_HairColor);
        leavingTab = 1;
    } else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon) {
        int sex = self->sex;
        int tab = result - CreationInput_TabIcon;
        signed char furthestTab = self->furthestState[sex];
        if (tab <= furthestTab) {
            signed char currentTab = self->state;
            if (tab != currentTab) {
                CharacterCreationUI_SwitchTab((unsigned char*)self, tab & 0xff);
                leavingTab = 1;
            }
        }
    }

    if (leavingTab != 0) {
        Vector3fix position = CharacterCreationUI_faceTabExitCameraPosition;
        Vector3fix target = CharacterCreationUI_faceTabExitCameraTarget;
        Camera_EasePositionTo((struct Camera*)self->camera, (int)&position, CreationCamera_EaseSteps);
        Camera_EaseTargetTo((struct Camera*)self->camera, (int)&target, CreationCamera_EaseSteps);
    }
}
