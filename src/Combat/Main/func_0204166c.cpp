#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

// USA: func_0204166c
extern "C" ARM void func_0204166c(Struct_0204166c* slot) {
    slot->pixels = NULL;
    slot->unknown_4_ = 0;
    slot->unknown_8_ = -1;
    slot->x = 0;
    slot->y = 0;
    slot->depth = 0;
#if defined(jpn)
    slot->encodedCharacter[1] = 0;
    slot->encodedCharacter[0] = 0;
    slot->unknown_1a_ = 12;
    slot->unknown_16_0_ = 0;
    slot->unknown_16_1_ = 0;
    slot->unknown_16_2_ = 0;
#else
    slot->character = NULL;
    slot->unknown_16_0_ = 0;
    slot->unknown_16_1_ = 0;
    slot->unknown_16_2_ = 0;
    slot->fontIndex = 0;
    slot->characterIndex = 0;
#endif
}
