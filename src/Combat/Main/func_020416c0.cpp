#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if defined(jpn)
// USA: func_020416c0
extern "C" ARM void func_02041bbc(Struct_0204166c* slot) {
    slot->pixels = NULL;
    slot->unknown_4_ = 0;
    slot->unknown_8_ = -1;
    slot->x = 0;
    slot->y = 0;
    slot->depth = 0;
    slot->encodedCharacter[1] = 0;
    slot->encodedCharacter[0] = 0;
    slot->unknown_1a_ = 12;
    slot->unknown_16_0_ = 0;
    slot->unknown_16_1_ = 0;
    slot->unknown_16_2_ = 0;
}
#else
// USA: func_020416c0
extern "C" ARM void func_020416c0(Struct_0204166c* slot) {
    func_0204166c(slot);
}
#endif
