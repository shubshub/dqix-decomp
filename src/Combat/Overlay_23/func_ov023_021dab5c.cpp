#include <globaldefs.h>

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteAffineTransform.h"

int GridCursor_GetCount(void*);
extern "C" void func_0205ac40(SpriteContext0205ac40*, B174Outer*);

extern "C" ARM void func_ov023_021dab5c(CharacterCreationUI* self, int x, int y, int width, int height) {
    int fixedHeight = height << 12;
    int fx = x << 12;
    int fy = y << 12;
    int minX, maxX, minY, maxY;
    if (self->state == 1) {
        int sumX = fx + (width << 12);
        int sumY = fy + fixedHeight;
        minX = fx - 0x7000;
        minY = fy - 0x7000;
        maxX = sumX - 0x1000;
        maxY = sumY - 0x1000;
        if (GridCursor_GetCount(&self->navigation) == 8 && self->navigation.rows == 1) {
            minX = fx - 0x4000;
            minY = fy - 0x4000;
            maxX = sumX - 0x4000;
            maxY = sumY - 0x4000;
        }
    } else {
        int var9 = var1 + (arg3 << 12);
        int var10 = var2 + var0;
        var3 = var1 - 0x4000;
        var5 = var2 - 0x4000;
        var4 = var9 - 0x4000;
        var6 = var10 - 0x4000;
    }
    fix32_t* position = self->subSprites[21].position;
    position[0] = minX;
    position[1] = minY;
    position = self->subSprites[22].position;
    position[0] = maxX;
    position[1] = minY;
    position = self->subSprites[23].position;
    position[0] = minX;
    position[1] = maxY;
    position = self->subSprites[24].position;
    position[0] = maxX;
    position[1] = maxY;
    for (int i = 0; i < 4; ++i)
        func_0205ac40(self->subSpriteContext, &self->subSprites[i + 21]);
}
#else
int GridCursor_GetCount(void* obj);
extern "C" void func_0205ac40(void* dst, void* entry);

// USA: func_ov023_021dab5c
extern "C" ARM void func_ov023_021dab5c(void* arg0, int arg1, int arg2, int arg3, int arg4) {
    char* var13 = (char*)arg0;
    int var14 = arg4 << 12;
    int var15 = arg1 << 12;
    int var16 = arg2 << 12;
    int var17, var18, var19, var20;

    if (*(signed char*)(o + 0xc58) == 1) {
        int sumX = fx + (a3 << 12);
        int sumY = fy + a4s;
        minX = fx - 0x7000;
        minY = fy - 0x7000;
        maxX = sumX - 0x1000;
        maxY = sumY - 0x1000;
        if (GridCursor_GetCount(o + 0xbec) == 8 && *(int*)(o + 0xbf8) == 1) {
            minX = fx - 0x4000;
            minY = fy - 0x4000;
            maxX = sumX - 0x4000;
            maxY = sumY - 0x4000;
        }
    } else {
        int var23 = var15 + (arg3 << 12);
        int var24 = var16 + var14;
        var17 = var15 - 0x4000;
        var18 = var16 - 0x4000;
        var19 = var23 - 0x4000;
        var20 = var24 - 0x4000;
    }

    char* var25 = *(char**)(var13 + 0x7e8);
    *(int*)(var25 + 0x35c) = var17;
    *(int*)(var25 + 0x360) = var18;
    *(int*)(var25 + 0x384) = var19;
    *(int*)(var25 + 0x388) = var18;
    *(int*)(var25 + 0x3ac) = var17;
    *(int*)(var25 + 0x3b0) = var20;
    *(int*)(var25 + 0x3d4) = var19;
    *(int*)(var25 + 0x3d8) = var20;

    int var26;
    for (var26 = 0; var26 < 4; var26++) {
        func_0205ac40(*(void**)(var13 + 0x7e4), var25 + (var26 + 0x15) * 0x28);
    }
}
#endif
