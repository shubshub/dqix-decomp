#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);

struct Struct_0205d5d0;
extern "C" int func_0205d5d0(struct Struct_0205d5d0* arg0, int arg1, int arg2, int arg3, unsigned char arg4);

struct Struct_ov023_021da1dc {
    char unknown_0_[0x30];
    int unknown_30_;
};

struct Struct_ov023_021da1dc_2 {
    char unknown_0_[0xf8];
    void* unknown_f8_;
    char unknown_fc_[0x2b4 - 0xfc];
    char unknown_2b4_[0xd85 - 0x2b4];
    unsigned char unknown_d85_;
};

extern "C" void CharacterCreationUI_WriteYesNoText(CharacterCreation_021da1dc* self, char* text, int highlighted);

static inline Struct_ov023_021da1dc* inline_ov023_021da1dc(void* arg0)
{
    return (Struct_ov023_021da1dc*)((char*)arg0 + 4);
}

// USA: CharacterCreationUI_RefreshYesNoMenu
#if defined(jpn)

struct Struct_ov023_021da1dc_3 {
    char unknown_0_[0xd8];
    void* unknown_d8_;
    char unknown_dc_[0x278 - 0xdc];
    char unknown_278_[0xd49 - 0x278];
    unsigned char unknown_d49_;
};

// Overlay 23, originally func_ov023_021da1dc (USA/EUR 0x021da1dc, JPN 0x021da9a8)
extern "C" ARM void CharacterCreationUI_RefreshYesNoMenu(CharacterCreation_021da9a8* self)
{
    unsigned char var0 = arg0->unknown_d49_;
    if (var0 != 0)
    {
        int var1 = 0;
        if (var0 == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            Struct_ov023_021da1dc* var2 = inline_ov023_021da1dc(arg0->unknown_278_);
            if (var2->unknown_30_ < 0)
                return;
            var1 = 1;
        }
        memset(self->unk_d8, 0, 0x800);
        CharacterCreationUI_WriteYesNoText((CharacterCreation_021da1dc*)self, (char*)self->unk_d8, highlighted);
        TryApplyElemFields0205d5d0((StructA0205d5d0*)self->window1, 1, (int)self->unk_d8, 0);
    }
}
#else
extern "C" ARM void CharacterCreationUI_RefreshYesNoMenu(CharacterCreation_021da1dc* self)
{
    unsigned char var3 = arg0->unknown_d85_;
    if (var3 != 0)
    {
        int var4 = 0;
        if (var3 == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            Struct_ov023_021da1dc* var5 = inline_ov023_021da1dc(arg0->unknown_2b4_);
            if (var5->unknown_30_ < 0)
                return;
            var4 = 1;
        }
        char* text = (char*)self->unk_f8;
        memset(text, 0, 0x960);
        CharacterCreationUI_WriteYesNoText(self, text, highlighted);
        TryApplyElemFields0205d5d0((StructA0205d5d0*)self->window1, 1, (int)text, 0, 1);
    }
}
#endif
