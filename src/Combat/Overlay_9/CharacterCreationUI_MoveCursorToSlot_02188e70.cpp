#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_02188e70 (USA/EUR 0x02188e70, JPN 0x02189d30)
extern "C" ARM void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* editor, int choice) {
    CreationSlotLayout* grid = &editor->grid;
    int y;
    int width;
    int height;
    int stepY;
    int columns = grid->columns;
    y = grid->y;
    width = grid->width;
    height = grid->height;
    stepY = grid->stepY;
#if defined(jpn)
    int var6 = arg1 % var5;
    int var7 = arg1 / var5;
    arg0->unknown_c4c_ = var0->unknown_10_ * var6 + var0->unknown_0_;
    arg0->unknown_c4e_ = var4 * var7 + var1;
#else
    arg0->unknown_c4c_ = var0->unknown_10_ * (arg1 % var5) + var0->unknown_0_;
    arg0->unknown_c4e_ = var4 * (arg1 / var5) + var1;
#endif
    arg0->unknown_c50_ = var2;
    arg0->unknown_c52_ = var3;
#if defined(jpn)
    if (arg0->unknown_c58_ == 8) {
        if (var6 >= 5)
            arg0->unknown_c4c_ += 8;
        if (var6 == var5 - 1) {
            arg0->unknown_c4c_ += 16;
            arg0->unknown_c50_ += 8;
            if (var7 == 5)
                arg0->unknown_c50_ += 8;
        }
    }
#endif
    arg0->unknown_c54_ = arg0->unknown_c4c_;
    arg0->unknown_c56_ = arg0->unknown_c4e_;
}
