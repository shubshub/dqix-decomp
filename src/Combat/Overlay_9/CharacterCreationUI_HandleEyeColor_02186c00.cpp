#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"


extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int choice);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
extern "C" void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);
#endif
extern "C" void Camera_EasePositionTo(struct Camera* camera, int position, int duration);
extern "C" void Camera_EaseTargetTo(struct Camera* camera, int target, int duration);

extern const Vector3fix CharacterCreationUI_eyeTabCameraPosition;
extern const Vector3fix CharacterCreationUI_eyeTabCameraTarget;
extern const Vector3fix CharacterCreationUI_eyeTabExitCameraPosition;
extern const Vector3fix CharacterCreationUI_eyeTabExitCameraTarget;

// Overlay 9, originally func_ov009_02186c00 (USA/EUR 0x02186c00, JPN 0x02187d2c)
extern "C" ARM void CharacterCreationUI_HandleEyeColor(CharacterCreationUI* self)
{
    if (self->step == ChoiceTabStep_Setup)
    {
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->eyeColor[self->sex]);
        Vector3fix position = CharacterCreationUI_eyeTabCameraPosition;
        Vector3fix target = CharacterCreationUI_eyeTabCameraTarget;
        Camera_EasePositionTo((struct Camera*)self->camera, (int)&position, CreationCamera_EaseSteps);
        Camera_EaseTargetTo((struct Camera*)self->camera, (int)&target, CreationCamera_EaseSteps);
        self->targetAngle = CreationAngle_Default;
        self->flags = (self->flags | CreationFlag_TurnToTarget) & ~CreationFlag_StylusRotation;
        self->step++;
    }
    else if (self->step == ChoiceTabStep_ShowChoice)
    {
        if (self->flags & CreationFlag_TabLoading)
            return;
        CharacterCreationUI_ApplyChoice(self, self->eyeColor[self->sex]);
        self->step++;
    }
    else if (self->step == ChoiceTabStep_Input)
    {
        if (!(self->flags & CreationFlag_StylusRotation) && !(self->flags & CreationFlag_TurnToTarget))
            self->flags |= CreationFlag_StylusRotation;
        int result = CharacterCreationUI_HandleInput(self);
        int leavingTab = 0;
        if (result == CreationInput_Confirm)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NameEntry);
            leavingTab = 1;
        }
        else if (result == CreationInput_Back)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_SkinColor);
            leavingTab = 1;
        }
        else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon)
        {
            int tab = result - CreationInput_TabIcon;
            if (tab <= self->furthestState[self->sex] && tab != self->state)
            {
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)tab);
                leavingTab = 1;
            }
        }
        if (leavingTab)
        {
            Vector3fix position = CharacterCreationUI_eyeTabExitCameraPosition;
            Vector3fix target = CharacterCreationUI_eyeTabExitCameraTarget;
            Camera_EasePositionTo((struct Camera*)self->camera, (int)&position, CreationCamera_EaseSteps);
            Camera_EaseTargetTo((struct Camera*)self->camera, (int)&target, CreationCamera_EaseSteps);
        }
    }
}
