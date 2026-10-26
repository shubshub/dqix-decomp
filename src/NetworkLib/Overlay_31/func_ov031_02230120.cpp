#include <globaldefs.h>

struct Struct_ov031_02230120_2 {
    union {
        unsigned long attributes;
        struct { unsigned short unknown_0_; unsigned short unknown_2_; };
        struct {
            unsigned long y : 8;
            unsigned long unknown_1_0_ : 2;
            unsigned long objMode : 2;
            unsigned long unknown_1_4_ : 1;
            unsigned long colorMode : 1;
            unsigned long shape : 2;
            unsigned long x : 9;
            unsigned long unknown_3_1_ : 5;
            unsigned long size : 2;
        };
        struct {
            unsigned long unused0 : 28;
            unsigned long unknown_3_4_ : 1;
            unsigned long unknown_3_5_ : 1;
            unsigned long unused1 : 2;
        };
    };
    union {
        struct { unsigned short unknown_4_; unsigned short unknown_6_; };
        unsigned long unknown1_4_;
        struct {
            unsigned long unknown_4_0_ : 10;
            unsigned long priority : 2;
            unsigned long unknown_5_4_ : 4;
            unsigned long unknown_6_0_ : 16;
        };
    };
};
struct Struct_ov031_02230120 {
    unsigned char unknown_0_[0x18];
    Struct_ov031_02230120_2* sprites[7];
    Struct_ov031_02230120_2* selected;
    unsigned char unknown_38_[0xc];
    unsigned char unknown_44_;
};
struct Struct_ov031_02290ca0_14 {
    unsigned char unknown_0_[4];
    unsigned short position;
    unsigned short unknown_6_;
    Struct_ov031_02230120* manager;
};
extern Struct_ov031_02290ca0_14 data_ov031_02290ca0;
extern "C" int FastIntDivide(int, int);
extern "C" int FastIntModulus(int, int);

static inline void inline_ov031_02230120(const Struct_ov031_02230120_2* sprite, unsigned long* x, unsigned long* y) {
    *x = (sprite->attributes & 0x1ff0000) >> 16;
    *y = sprite->attributes & 0xff;
}

static inline void inline_ov031_02230120_2(Struct_ov031_02230120_2* sprite, int x, int y) {
    sprite->attributes = (sprite->attributes & ~0x01ff00ff) | (y & 0xff) | ((x & 0x1ff) << 16);
}

// USA: func_ov031_02230120
extern "C" ARM void func_ov031_02230120() {
    int spriteX;
    int spriteY;
    int row = FastIntDivide(data_ov031_02290ca0.position, 29);
    int y = 52 - FastIntModulus(data_ov031_02290ca0.position, 29);
    if (data_ov031_02290ca0.manager->selected) {
        if (row == 0) spriteX = 38;
        else spriteX = 256;
        inline_ov031_02230120_2(data_ov031_02290ca0.manager->selected, spriteX, y);
    }
    int cur = y;
    int i = 0;
    do {
        Struct_ov031_02230120_2* sprite = data_ov031_02290ca0.manager->sprites[i];
        inline_ov031_02230120(sprite, (unsigned long*)&spriteX, (unsigned long*)&spriteY);
        inline_ov031_02230120_2(sprite, spriteX, cur);
        cur += 29;
    } while (++i < 5);
    if (row <= 2) {
        Struct_ov031_02230120_2* sprite = data_ov031_02290ca0.manager->sprites[5];
        inline_ov031_02230120(sprite, (unsigned long*)&spriteX, (unsigned long*)&spriteY);
        inline_ov031_02230120_2(sprite, spriteX, y + (2 - row) * 29);
    } else {
        inline_ov031_02230120_2(data_ov031_02290ca0.manager->sprites[5], 256, 0);
    }
    if (row >= 2 && row <= 6) {
        Struct_ov031_02230120_2* sprite = data_ov031_02290ca0.manager->sprites[6];
        inline_ov031_02230120(sprite, (unsigned long*)&spriteX, (unsigned long*)&spriteY);
        inline_ov031_02230120_2(sprite, spriteX, y + (6 - row) * 29);
    } else {
        inline_ov031_02230120_2(data_ov031_02290ca0.manager->sprites[6], 256, 0);
    }
    data_ov031_02290ca0.manager->unknown_44_ = 1;
}
