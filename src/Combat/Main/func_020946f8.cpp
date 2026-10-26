#include <globaldefs.h>

struct Struct_02094654_2 {
    unsigned int attributes01;
    unsigned short unknown_4_;
    short affineParameter;
};

enum {
    Enum_020946f8_3 = 3,
    Enum_020946f8_256 = 0x100,
    Enum_020946f8_768 = 0x300
};

// USA: func_020946f8
extern "C" ARM void func_020946f8(Struct_02094654_2* sprite, int x, int y, int priority,
                            int mode, int arg5, int effect, int shape, int colorMode,
                            int characterIndex, int arg10, int affineIndex) {
    if (effect == Enum_020946f8_256 || effect == Enum_020946f8_768) {
        if (mode == Enum_020946f8_3) {
            sprite->attributes01 = (y & 0xff) | (affineIndex << 25) | (mode << 10) | (arg5 << 12) | shape | ((x & 0x1ff) << 16) | effect;
        } else {
            sprite->attributes01 = (y & 0xff) | ((affineIndex << 25) | (colorMode << 13)) | (mode << 10) | (arg5 << 12) | shape | ((x & 0x1ff) << 16) | effect;
        }
    } else {
        if (mode == Enum_020946f8_3) {
            sprite->attributes01 = (y & 0xff) | (mode << 10) | (arg5 << 12) | shape | ((x & 0x1ff) << 16) | effect;
        } else {
            sprite->attributes01 = (y & 0xff) | (colorMode << 13) | (mode << 10) | (arg5 << 12) | shape | ((x & 0x1ff) << 16) | effect;
        }
    }
    sprite->unknown_4_ = characterIndex | (priority << 10) | (arg10 << 12);
}
