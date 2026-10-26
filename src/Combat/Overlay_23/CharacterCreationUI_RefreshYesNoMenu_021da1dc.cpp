#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/CharacterCreationUI.h"
#include "Graphics/Window.h"
#include "Combat/TryApplyElemFields.h"

extern "C" void* memset(void* dst, int value, unsigned int length);

// A window's touch grid (CreationWindow::frame), as far as it is read here.
struct TouchGrid {
    char unk_0[0x30];
    int touchedCell;    // the cell the last stylus press hit, -1 for none (TouchGrid_SetTouchedCell)
};

extern "C" void CharacterCreationUI_WriteYesNoText(CharacterCreationUI* self, char* text, int highlighted);

// CreationWindow::frame, from the window's address.
static inline TouchGrid* GetTouchGrid(void* window)
{
    return (TouchGrid*)((char*)window + 4);
}

#if defined(jpn)
// Overlay 23, originally func_ov023_021da1dc (USA/EUR 0x021da1dc, JPN 0x021da9a8)
extern "C" ARM void CharacterCreationUI_RefreshYesNoMenu(CharacterCreationUI* self)
{
    unsigned char input = self->windowInput;
    if (input != 0)
    {
        int highlighted = 0;
        if (input == WindowInput_TouchMoved && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            TouchGrid* touchGrid = GetTouchGrid(&self->windows[CreationWindowIndex_Bottom]);
            if (touchGrid->touchedCell < 0)
                return;
            highlighted = 1;
        }
        memset(self->textBuffer, 0, 0x800);
        CharacterCreationUI_WriteYesNoText(self, self->textBuffer, highlighted);
        ((int (*)(struct StructA0205d5d0*, int, int, int))Window_SetPaneText)((StructA0205d5d0*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_YesNoPane, (int)self->textBuffer, 0);
    }
}
#else
// Overlay 23, originally func_ov023_021da1dc (USA/EUR 0x021da1dc, JPN 0x021da9a8)
extern "C" ARM void CharacterCreationUI_RefreshYesNoMenu(CharacterCreationUI* self)
{
    unsigned char input = self->windowInput;
    if (input != 0)
    {
        int highlighted = 0;
        if (input == WindowInput_TouchMoved && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            TouchGrid* touchGrid = GetTouchGrid(&self->windows[CreationWindowIndex_Bottom]);
            if (touchGrid->touchedCell < 0)
                return;
            highlighted = 1;
        }
        char* text = self->textBuffer;
        memset(text, 0, 0x960);
        CharacterCreationUI_WriteYesNoText(self, text, highlighted);
        Window_SetPaneText((StructA0205d5d0*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_YesNoPane, (int)text, 0, 1);
    }
}
#endif
