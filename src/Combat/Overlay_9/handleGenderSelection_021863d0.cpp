#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov009_021863d0 {
    char unknown_0_[0xc12];
    unsigned char unknown_c12_;
};

int GetWord0x0_0200fb8c(int* gameState);
extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int choice);
extern "C" void applyCreationChoice(CharacterCreationUI* self, int choice);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
extern "C" void clearModelPart(CharacterModel* character, int part);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" void func_ov009_021855dc(unsigned char* arg0, int arg1);
#endif

// Overlay 9, originally func_ov009_021863d0 (USA/EUR 0x021863d0, JPN 0x02187500)
extern "C" ARM void handleGenderSelection(CharacterCreationUI* self)
{
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = (GameResources*)func_0200fb8c((int*)var0);
    if (arg0->unknown_c59_ == 0)
    {
        if (GetBrightness((GameResources*)var1, false) == -16 &&
            GetBrightness((GameResources*)var1, true) == -16)
        {
            if (arg0->unknown_d9c_ & 0x80)
                return;
            SetBrightness(var1, 0, 15);
        }
        func_ov009_02188c2c(arg0);
        func_ov009_02188d9c(arg0);
        func_ov009_02188e70(arg0, arg0->unknown_da3_);
        arg0->unknown_c59_++;
    }
    if (arg0->unknown_c59_ == 1)
    {
        if (IsBrightnessTransitionActive(var1))
            return;
        arg0->unknown_d9c_ |= 1;
        arg0->unknown_c59_++;
    }
    else if (arg0->unknown_c59_ == 2)
    {
        if (arg0->unknown_d9c_ & 0x80)
            return;
        applyCreationChoice(self, self->sex);
        self->step++;
    }
    else if (arg0->unknown_c59_ == 3)
    {
        int var2 = func_ov009_02188ee8(arg0);
        if (var2 != arg0->unknown_c58_)
        {
            Struct_ov009_021863d0* var3 = (Struct_ov009_021863d0*)arg0->unknown_7fc_;
            if (var3->unknown_c12_ == 0)
            {
#if defined(jpn)
                clearModelPart((CharacterModel*)self->nextCharacter, 0);
                clearModelPart((CharacterModel*)self->nextCharacter, 2);
                clearModelPart((CharacterModel*)self->nextCharacter, 3);
                clearModelPart((CharacterModel*)self->nextCharacter, 4);
#else
                clearModelPart(next, 0);
                clearModelPart(next, 2);
                clearModelPart(next, 3);
                clearModelPart(next, 4);
#endif
            }
        }
        if (var2 == -2)
        {
            func_ov009_021855dc((unsigned char*)arg0, 2);
            return;
        }
        if (var2 == -3)
        {
            if (arg0->unknown_d95_ == 1)
                arg0->unknown_d9c_ &= ~0x400;
            else if (arg0->unknown_d95_ == 0)
                #if defined(jpn)
                *((unsigned char*)var0 + 0x6174) = 0;
#else
                *((unsigned char*)var0 + 0x63d4) = 0;
#endif
            func_ov009_021855dc((unsigned char*)arg0, 11);
            return;
        }
        if (var2 >= 101 && var2 <= 108)
        {
            int var4 = var2 - 100;
            if (var4 <= arg0->unknown_da0_[arg0->unknown_da3_] && var4 != arg0->unknown_c58_)
                func_ov009_021855dc((unsigned char*)arg0, (unsigned char)var4);
        }
    }
}
