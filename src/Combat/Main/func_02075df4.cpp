#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

extern const fix16_t data_020e9450[4096 * 2];

struct Struct_02075df4 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    short unknown_6_;
};

struct Struct_02075df4_2 {
    fix32_t x;
    fix32_t y;
};

struct Struct_02075df4_3 {
    int** unknown_0_;
    int** unknown_4_;
    int** unknown_8_;
    int** unknown_c_;
    short* counts;
    Struct_02075df4* oam;
    char unknown18[0x10];
    Struct_02075df4_2 scale;
    unsigned short angle;
    char unknown32[0xa];
    int palette;
    int priority;
    int matrixIndex;
    int mode;
    int effect;
    int colorMode;
};

static inline fix32_t inline_0205b0d8(int sample) {
    return data_020e9450[sample * 2];
}

static inline fix32_t inline_0205b0d8_2(int sample) {
    return data_020e9450[sample * 2 + 1];
}

static inline bool inline_02075df4(int effect) {
    return effect == 0x100 || effect == 0x300;
}

// USA: func_02075df4
extern "C" ARM int func_02075df4(Struct_02075df4_3* cells, int index, int x, int y) {
    int* var0 = cells->unknown_8_[index];
    int* var1 = cells->unknown_c_[index];
    int* var2 = cells->unknown_0_[index];
    int* var3 = cells->unknown_4_[index];
    bool var4 = false;
    if (inline_02075df4(cells->effect)) {
        var4 = true;
    }
    Struct_0205ac40_3* matrix = NULL;
    Struct_0205ac40_3 var6;
    Struct_0205ac40_3 inverse;
    Struct_0205ac40_3 rotation;
    short i;

    if (var4) {
        unsigned short angle = cells->angle;
        Struct_02075df4_2 scale = cells->scale;
        fix32_t cosine = inline_0205b0d8_2(angle >> 4);
        func_020c111c(&rotation, inline_0205b0d8(angle >> 4), cosine);
        func_020c1128(&rotation, &var6, scale.x, scale.y);
        func_020c1128(&rotation, &inverse, fix32_Divide(0x1000, scale.x),
                                        fix32_Divide(0x1000, scale.y));
        matrix = &var6;
    }
    if (matrix != NULL) {
        Struct_02075df4* oam = cells->oam;
        oam[0].unknown_6_ = inverse.values[0] >> 4;
        oam[1].unknown_6_ = inverse.values[1] >> 4;
        oam[2].unknown_6_ = inverse.values[2] >> 4;
        oam[3].unknown_6_ = inverse.values[3] >> 4;
    }
    for (i = 0; i < cells->counts[index]; i++) {
        int offsetX = var0[i];
        int offsetY = var1[i];
        if (matrix != NULL) {
            offsetX = (cells->scale.x * offsetX) >> 12;
            offsetY = (cells->scale.y * offsetY) >> 12;
        }
        {
            int px;
            int var17;
            Struct_02075df4* oam;
            int priority;
            int mode;
            int effect;
            int shape;
            int color;
            int var24;
            int var25;
            int var26;
            px = offsetX + x;
            var17 = offsetY + y;
            oam = &cells->oam[i];
            var26 = cells->matrixIndex;
            var25 = cells->palette;
            var24 = var2[i];
            color = cells->colorMode;
            shape = var3[i];
            effect = cells->effect;
            mode = cells->mode;
            priority = cells->priority;
            if (inline_02075df4(effect)) {
                if (mode == 3) {
                    oam->unknown_0_ = effect | ((shape | (((var17 & 0xff) | (var26 << 25)) | (mode << 10))) |
                                            ((px & 0x1ff) << 16));
                } else {
                    oam->unknown_0_ = effect | ((shape | (((var17 & 0xff) | ((var26 << 25) | (color << 13))) |
                                                      (mode << 10))) |
                                            ((px & 0x1ff) << 16));
                }
            } else {
                if (mode == 3) {
                    oam->unknown_0_ = effect | ((shape | ((var17 & 0xff) | (mode << 10))) | ((px & 0x1ff) << 16));
                } else {
                    oam->unknown_0_ = effect | ((shape | ((var17 & 0xff) | (color << 13) | (mode << 10))) |
                                            ((px & 0x1ff) << 16));
                }
            }
            oam->unknown_4_ = (var24 | (priority << 10)) | (var25 << 12);
        }
    }
    return cells->counts[index];
}
