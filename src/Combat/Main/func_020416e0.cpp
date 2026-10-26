#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageGlyphSlot.h"

// JPN: func_02041c10
extern "C" ARM void func_02041c10(Struct_0204166c* slot, const char* character, unsigned char* pixels, int arg3, unsigned int arg4, unsigned char arg5) {
    if (!pixels) return;
    func_0204166c(slot);
    slot->encodedCharacter[0] = character[0];
    slot->encodedCharacter[1] = character[1];
    slot->unknown_8_ = arg3;
    slot->pixels = pixels;
    slot->unknown_4_ = arg4;
    slot->unknown_1a_ = arg5;
    slot->unknown_16_0_ = 1;
    slot->unknown_16_1_ = 0;
    slot->unknown_16_2_ = 0;
}
#else

struct Struct_0204166c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned short f14;
    unsigned char unknown_16_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char unknown_16_3_ : 1;
    unsigned char pad16 : 4;
    unsigned char unknown_17_;
    int f18;
};

extern "C" void func_0204166c(struct Struct_0204166c* s);

// USA: func_020416e0
extern "C" ARM void func_020416e0(struct Struct_0204166c* s, unsigned char arg1, int arg2, int arg3, int arg4, int arg5, unsigned char arg6) {
    if (arg3 == 0) return;
    func_0204166c(s);
    s->unknown_17_ = arg1;
    s->f18 = arg2;
    s->f8 = arg4;
    s->f0 = arg3;
    s->f4 = arg5;
    s->unknown_16_0_ = 1;
    s->flag1 = 0;
    s->flag2 = 0;
    s->unknown_16_3_ = arg6;
}

#endif
