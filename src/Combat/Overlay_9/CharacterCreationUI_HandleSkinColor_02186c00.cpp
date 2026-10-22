#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
#endif

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int choice);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
#endif
extern "C" void func_0202ee38(char* arg0, int arg1, int arg2);
extern "C" void func_0202ee58(char* arg0, int arg1, int arg2);

#if defined(jpn)
#define data_ov009_0218a9f8 data_ov009_0218b9d4
#endif
extern const Vector3fix data_ov009_0218a9f8;
#if defined(jpn)
#define data_ov009_0218aa04 data_ov009_0218b9e0
#endif
extern const Vector3fix data_ov009_0218aa04;
#if defined(jpn)
#define data_ov009_0218aa10 data_ov009_0218b9ec
#endif
extern const Vector3fix data_ov009_0218aa10;
#if defined(jpn)
#define data_ov009_0218aa1c data_ov009_0218b9f8
#endif
extern const Vector3fix data_ov009_0218aa1c;

// USA: func_ov009_02186c00
extern "C" ARM void func_ov009_02186c00(Struct_ov009_021842a0* arg0)
{
    if (arg0->unknown_c59_ == 0)
    {
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->skinColor[self->sex]);
        Vector3fix position = data_ov009_0218a9f8;
        Vector3fix target = data_ov009_0218aa04;
        CallFunc020a0db8AtField0x16c_0202ee38((char*)self->camera, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58((char*)self->camera, (int)&target, 0x1e000);
        self->targetAngle = 0x1eb;
        self->flags = (self->flags | 8) & ~1;
        self->step++;
    }
    else if (arg0->unknown_c59_ == 1)
    {
        if (arg0->unknown_d9c_ & 0x80)
            return;
        CharacterCreationUI_ApplyChoice(self, self->skinColor[self->sex]);
        self->step++;
    }
    else if (arg0->unknown_c59_ == 2)
    {
        if (!(self->flags & 1) && !(self->flags & 8))
            self->flags |= 1;
        int result = CharacterCreationUI_HandleInput(self);
        int changed = 0;
        if (result == CreationInput_Confirm)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NameEntry);
            changed = 1;
        }
        else if (result == CreationInput_Back)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_EyeColor);
            changed = 1;
        }
        else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon)
        {
            int state = result - CreationInput_TabIcon;
            if (state <= self->furthestState[self->sex] && state != self->state)
            {
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)state);
                changed = 1;
            }
        }
        if (var3)
        {
            Vector3fix var5 = data_ov009_0218aa10;
            Vector3fix var6 = data_ov009_0218aa1c;
            func_0202ee38((char*)arg0->unknown_924_, (int)&var5, 0x1e000);
            func_0202ee58((char*)arg0->unknown_924_, (int)&var6, 0x1e000);
        }
    }
}
