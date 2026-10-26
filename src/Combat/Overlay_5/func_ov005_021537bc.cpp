#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

extern "C" void SprSprite_DrawGroup(void* object, int index, int mode);
struct Struct_02075db0;
extern "C" int func_02075db0(Struct_02075db0* object, int x, int y);

struct Struct_ov005_021537bc {
    unsigned char* backing;
    unsigned int unknown_4_;
    unsigned char pad8[0x28 - 8];
    unsigned int unknown_28_;
    unsigned int unknown_2c_;
    unsigned int unknown_30_;
    unsigned int unknown_34_;
    int unknown_38_;
};

// USA: func_ov005_021537bc
extern "C" ARM void func_ov005_021537bc(void* object, int mode, unsigned short value) {
    Struct_ov005_021537bc* self = (Struct_ov005_021537bc*)object;
    if (self->backing == 0) return;
    unsigned int x = self->unknown_28_;
    unsigned int y = self->unknown_2c_;
    int startX = (int)(x & ~0xfffU);
    int startY = (int)(y & ~0xfffU);
    int endX = (int)((x + self->unknown_30_ - self->unknown_4_) & ~0xfffU);
    int endY = (int)((y + self->unknown_34_ - self->unknown_4_) & ~0xfffU);
    int var7[4][2] = {
        { startX, startY },
        { endX, startY },
        { startX, endY },
        { endX, endY }
    };
    for (int i = 0; i < 4; ++i) {
        int px = var7[i][0];
        int var10 = var7[i][1];
        switch (mode) {
        case 0: {
            GXFIFO_MATRIX_PUSH = 0;
            int z = self->unknown_38_;
            GXFIFO_MATRIX_TRANSLATE = px;
            GXFIFO_MATRIX_TRANSLATE = var10;
            GXFIFO_MATRIX_TRANSLATE = z;
            *(unsigned short*)(self->backing + i * 0x88 + 0x80) = value;
            SprSprite_DrawGroup(self->backing + i * 0x88, 0, 1);
            GXFIFO_MATRIX_POP = 1;
            break;
        }
        case 1:
            func_02075db0((Struct_02075db0*)(self->backing + i * 0x70),
                px >> 12, var10 >> 12);
            break;
        case 2: {
            unsigned char* entry = self->backing + i * 0x28;
            *(int*)(entry + 0x14) = px;
            *(int*)(entry + 0x18) = var10;
            break;
        }
        }
    }
}
