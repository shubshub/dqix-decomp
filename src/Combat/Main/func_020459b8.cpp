#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageSystem.h"

struct Foo0207df50 {
    unsigned int first[10];
    unsigned int second[10];
    unsigned int unknown_50_;
};

struct Struct_02107800_4 {
    unsigned char* unknown_0_;
};

extern Struct_02107800_4 data_02107800;
extern const unsigned char data_020e7a8c[];
extern const short data_020e7aa6[];
extern const short data_020e7ab0[];

extern "C" void func_020416e0(Struct_0204166c*, unsigned char, int, int, int, int, unsigned char);
extern "C" void func_02045864(int x, int y, FontCharacter* glyph, unsigned char* dst, int width, int height,
                              unsigned char color, unsigned char font);

static inline unsigned int inline_020459b8(Foo0207df50* encoder) {
    return (encoder->unknown_50_ << 16) >> 13;
}

// USA: func_020459b8
extern "C" ARM int func_020459b8(MessageSystem* arg0, unsigned char arg1, FontCharacter* character,
                                 unsigned char font) {
    if (character == NULL) {
        return 0;
    }
    unsigned char* pixels = data_02107800.unknown_0_;
    unsigned char* var1 = arg0->unknown_17b8_;
    Struct_0204166c* slots = arg0->glyphs;
    int var3 = arg0->func_02042a90(arg0->unknown_2cc_, 4);
    if (var3 < 0) {
        return 0;
    }
    for (int i = 0; i < 0x80; i++) {
        if (var1[i] == 0) {
            if (arg0->encoder != NULL) {
                unsigned char* buf = pixels + (var3 << 7);
                Struct_0204166c* slot = &slots[i];
                bool var7 = false;
                bool var8 = false;
                if (arg0->unknown_19cc_ == 0) {
                    memset(buf, 0, 0x80);
                    if (arg0->unknown_195b_ & 0x80) {
                        var8 = true;
                        for (unsigned char j = 0; j < 5; j++) {
                            func_02045864(data_020e7aa6[j], data_020e7ab0[j], character, buf, 16, 16,
                                          data_020e7a8c[j], font);
                        }
                    } else if (arg0->unknown_195b_ & 2) {
                        var7 = true;
                        func_02045864(2, 2, character, buf, 16, 16, 1, font);
                        func_02045864(1, 1, character, buf, 16, 16, 0xf, font);
                    } else {
                        func_02045864(1, 1, character, buf, 16, 16, 0xf, font);
                    }
                }
                func_020416e0(slot, arg1, (int)character, (int)buf, var3,
                                          (i << 7) + inline_020459b8(arg0->encoder), font);
                if (var8) {
                    slot->unknown_16_2_ = 1;
                }
                if (var7) {
                    slot->unknown_16_1_ = 1;
                }
            }
            var1[i] = 1;
            return i;
        }
    }
    return 0;
}
